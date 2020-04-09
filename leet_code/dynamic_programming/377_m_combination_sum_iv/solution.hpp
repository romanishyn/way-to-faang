/*
https://leetcode.com/problems/combination-sum-iv/
*/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
//    int combinationSum4(vector<int>& nums, int target) {
//        if( target == 0 )
//            return 1;
//
//        int res = 0;
//        for( int num : nums ) {
//            if( ( target - num ) >= 0 )
//                res += combinationSum4( nums, target - num );
//        }
//
//        return res;
//    }

    int combinationSum4(vector<int>& nums, int target) {
        vector< long long> dp( target + 1 );
        dp[ 0 ] = 1;

        for( int i = 1; i <= target; ++i ) {
            for( int num : nums ) {
                if( ( i - num ) >= 0 )
                    dp[ i ] += dp[ i - num ];
            }
        }

        return dp[ target ];
    }
};
