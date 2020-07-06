/*
https://leetcode.com/problems/longest-increasing-subsequence/

 https://www.youtube.com/watch?v=fV-TF4OvZpk
*/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

/*
 *
 * TODO:
 * - impl recursion approach
 * - impl nlog(n)
 * */

namespace V1 {
class Solution {
public:
    int lengthOfLIS( vector< int > & nums ) {
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
} // namespace V1

namespace V2 {
/*
 * Time (N^2)
 * Space (N)
 * */
class Solution {
public:
    int lengthOfLIS( vector< int > & nums ) {
        if( nums.size() < 2 )
            return nums.size();

        int maxLength = 0;
        std::vector< int > dp( nums.size(), 1 );

        for( int i = 0; i < nums.size() - 1; ++i ) {
            for( int j = i + 1; j < nums.size(); ++j ) {
                if( nums[ i ] < nums[ j ] )
                    dp[ j ] = std::max( dp[ j ], dp[ i ] + 1 );

                maxLength = std::max( maxLength, dp[ j ] );
            }
        }

        return maxLength;
    }
};
} // namespace V2
