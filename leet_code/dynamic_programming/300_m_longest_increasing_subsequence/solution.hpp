/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

/*
 * TODO:
 * - impl recursion approach
 * - impl nlog(n)
 * */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if( nums.empty() )
            return 0;

        int res = 1;
        std::vector< int > dp( nums.size(), 1 );
        for( int i = 1; i < nums.size(); ++i ) {
            for( int j = 0; j < i; ++j ) {
                if( nums[ j ] < nums[ i ] ) {
                    dp[ i ] = std::max( dp[ i ], dp[ j ] + 1 );
                }
            }

            res = std::max( res, dp[ i ] );
        }

        return res;
    }


};
