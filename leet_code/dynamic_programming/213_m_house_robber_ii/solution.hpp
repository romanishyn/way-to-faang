/*
https://leetcode.com/problems/house-robber-ii/
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
//        if( size == 0 ) return 0;
//        if( size == 1 ) return nums[ 0 ];
//        if( size == 2 ) return std::max( nums[ 0 ], nums[ 1 ] );
//
//        return std::max(
//                rob_helper( nums, 0, size - 1 )
//            ,   rob_helper( nums, 1, size )
//        );
//    }
//
//    int rob_helper( vector< int > & nums, int begin, int end ) {
//        const int size = end - begin;
//
//        if( size == 0 ) return 0;
//        if( size == 1 ) return nums[ begin ];
//        if( size == 2 ) return std::max( nums[ begin ], nums[ begin + 1 ] );
//
//        vector< int > dp( size );
//        dp[ 0 ] = nums[ begin ];
//        dp[ 1 ] = std::max( nums[ begin ], nums[ begin + 1 ] );
//
//        for( int i = 2; i < size; ++i ) {
//            dp[ i ] = std::max( dp[ i - 2 ] + nums[ begin + i ], dp[ i - 1 ] );
//        }
//
//        return dp.back();
//    }


    int rob(vector<int>& nums) {
        const int size = nums.size();
        if( size == 1 )
            return nums[ 0 ];

        return std::max(
                rob_helper( nums, 0, size - 1 )
            ,   rob_helper( nums, 1, size )
        );
    }

    int rob_helper( const vector<int>& nums, int begin, int end ) {
        int prev = 0;
        int cur = 0;

        for( int i = begin; i < end; ++i ) {
            const int tempCur = std::max( prev + nums[ i ], cur );
            prev = cur;
            cur = tempCur;
        }

        return cur;
    }
};
