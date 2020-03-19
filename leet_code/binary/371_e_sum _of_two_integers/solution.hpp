//https://leetcode.com/problems/sum-of-two-integers/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        bool carry = false;

        for( int i = 0; i < 32; ++i ) {
            const bool isAOne = static_cast< bool >( a & ( 1 << i ) );
            const bool isBOne = static_cast< bool >( b & ( 1 << i ) );

            if( isAOne && isBOne ) {
                if( carry )
                    result |= 1 << i;

                carry = true;
            } else if( !isAOne && !isBOne ) {
                if( carry )
                    result |= 1 << i;

                carry = false;
            } else {
                if( !carry )
                    result |= 1 << i;
            }
        }

        return result;
    }
};
