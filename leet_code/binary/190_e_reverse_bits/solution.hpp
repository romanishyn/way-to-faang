//https://leetcode.com/problems/reverse-bits/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int left = 0;
        int right = 31;

        while( left < right ) {
            if( (bool)( n & ( 1 << left ) ) != (bool)( n & ( 1 << right ) ) ) {
                if( n & ( 1 << left ) ) {
                    n &= ~( 1 << left );
                    n |= 1 << right;
                } else {
                    n &= ~( 1 << right );
                    n |= 1 << left;
                }
            }

            ++left;
            --right;
        }

        return n;
    }
};
