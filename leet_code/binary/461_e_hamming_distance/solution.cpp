/*
https://leetcode.com/problems/hamming-distance/
 */

#include "bitset"

namespace V1 {
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;

        for( int i = 0; i < 32; ++i )
            distance += ( x & ( 1 << i ) ) ^ ( y & ( 1 << i ) ) ? 1 : 0;

        return distance;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;

        int difference = x ^ y;

        while( difference ) {
            if( difference & 1 )
                ++distance;

            difference >>= 1;
        }

        return distance;
    }
};
} // namespace V2

namespace V3 {
class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;

        int difference = x ^ y;

        while( difference ) {
            ++distance;
            difference &= difference - 1;
        }

        return distance;
    }
};
} // namespace V3

namespace V4 {
class Solution {
public:
    int hammingDistance(int x, int y) {
        return std::bitset< 32 >( x ^ y ).count();
    }
};
} // namespace V4
