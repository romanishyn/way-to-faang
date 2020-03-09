// https://leetcode.com/problems/maximum-subarray/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    //
//    int maxSubArray(vector<int>& nums) {
//        int currentSum = 0;
//        int maxSum = std::numeric_limits< int >::min();
//
//        for( int x : nums ) {
//            currentSum = std::max( x, currentSum + x );
//            maxSum = std::max( currentSum, maxSum );
//        }
//
//        return maxSum;
//    }



// Divide and conquer approach

//    [-2,1,-3,4,-1,2,1,-5,4]
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayImpl( nums, 0, nums.size() );
    }

    int maxSubArrayImpl( const vector< int >& v, int lowIdx, int highIdx ) {
        if( highIdx - lowIdx == 1 )
            return v[ lowIdx ];

        const int midIdx = ( lowIdx + highIdx ) >> 1;

        return max(
                maxSubArrayImpl( v, lowIdx, midIdx )
            ,   maxSubArrayImpl( v, midIdx, highIdx )
            ,   maxCrossingSubArray( v, lowIdx, midIdx, highIdx )
            );
    }

    int maxCrossingSubArray( const vector< int >& v, int lowIdx, int midIdx, int highIdx ) {
        int sum = 0;

        int leftSum = std::numeric_limits< int >::min();
        for( int i = midIdx - 1; i >= lowIdx; --i ) {
            sum += v[ i ];
            leftSum = std::max( leftSum, sum );
        }

        sum = 0;

        int rightSum = std::numeric_limits< int >::min();
        for( int i = midIdx; i < highIdx; ++i ) {
            sum += v[ i ];
            rightSum = std::max( rightSum, sum );
        }

        return leftSum + rightSum;
    }

    int max( int a, int b, int c ) {
        return std::max( std::max( a, b ), c );
    }
};
