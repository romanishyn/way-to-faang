//https://leetcode.com/problems/number-of-1-bits/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
//    int hammingWeight(uint32_t n) {
//        int count = 0;
//        while( n ) {
//            ++count;
//            n &= n - 1;
//        }
//
//        return count;
//    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        for( int i = 0; i < 32; ++i ) {
            if( n & ( 1 << i ) )
                ++count;
        }

        return count;
    }
};
