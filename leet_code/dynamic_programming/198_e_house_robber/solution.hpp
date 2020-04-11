/*
https://leetcode.com/problems/house-robber/
*/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
//    int rob(vector<int>& nums) {
//        const int size = nums.size();
//
//        if( size == 0 )
//            return 0;
//        if( size == 1 )
//            return nums[ 0 ];
//        if( size == 2 )
//            return std::max( nums[ 0 ], nums[ 1 ] );
//
//        std::vector< int > dp( size );
//        dp[ 0 ] = nums[ 0 ];
//        dp[ 1 ] = std::max( nums[ 0 ], nums[ 1 ] );
//
//        for( int i = 2; i < size; ++i ) {
//            dp[ i ] = std::max( nums[ i ] + dp[ i - 2 ], dp[ i - 1 ] );
//        }
//
//        return dp.back();
//    }

    int rob(vector<int>& nums) {
        const int size = nums.size();

        if( size == 0 )
            return 0;
        if( size == 1 )
            return nums[ 0 ];
        if( size == 2 )
            return std::max( nums[ 0 ], nums[ 1 ] );

        int prev = nums[ 0 ];
        int cur = std::max( nums[ 0 ], nums[ 1 ] );

        for( int i = 2; i < size; ++i ) {
            const int tempCur = cur;

            cur = std::max( prev + nums[ i ], cur );

            prev = tempCur;
        }

        return cur;
    }
};
