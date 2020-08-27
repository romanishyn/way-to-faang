/*
https://leetcode.com/problems/number-complement/
*/

#include <cmath>

namespace {
/*
Count size of part which need modify. Set ones in this range and XOR this range with num

Time O(1)
Space O(1)
*/
class Solution {
public:
    int findComplement(int num) {
        int counter = 0;
        int bitmask = num;
        while( bitmask ) {
            ++counter;
            bitmask >>= 1;
        }

        bitmask = std::pow( 2, counter ) - 1;

        return num ^ bitmask;
    }
};
} // namespace

namespace {
/*
Time O(1)
Space O(1)
*/
class Solution {
public:
    int findComplement(int num) {
        int bitmask = num;
        bitmask |= bitmask >> 1;
        bitmask |= bitmask >> 2;
        bitmask |= bitmask >> 4;
        bitmask |= bitmask >> 8;
        bitmask |= bitmask >> 16;

        return num ^ bitmask;
    }
};
} // namespace

