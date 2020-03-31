// https://leetcode.com/problems/maximum-product-subarray/

#pragma once

#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
    // Wrong
//    int maxProduct(vector<int>& nums) {
//        int curMax = nums[ 0 ];
//        int maxProd = curMax;
//
//        for( int i = 1; i < nums.size(); ++i ) {
//            const int temp = curMax * nums[ i ];
//
//            if( temp > curMax )
//                curMax = temp;
//            else
//                curMax = nums[ i ];
//
//            maxProd = std::max( curMax, maxProd );
//        }
//
//        return maxProd;
//    }

//    [2,-5,-2,-4,3] -> 24
//    [-2, 0, -1] -> 0
//    int maxProduct(vector<int>& nums) {
//        int totalProd = 1;
//        int currProd = 1;
//        int maxProd = std::numeric_limits< int >::min();
//
//        for( int x : nums ) {
//            currProd = std::max( x, currProd * x );
//
//            if( totalProd == 0 )
//                totalProd = x;
//            else
//                totalProd *= x;
//
//            maxProd = std::max( maxProd, std::max( currProd, totalProd ) );
//        }
//
//        return maxProd;
//    }

//    int maxProduct(vector<int>& nums) {
//        int maxProd = std::numeric_limits< int >::min();
//        for( int i = 0; i < nums.size(); ++i ) {
//            int currProd = 1;
//            for( int j = i; j < nums.size(); ++j ) {
//                currProd *= nums[ j ];
//                maxProd = std::max( maxProd, currProd );
//            }
//        }
//
//        return maxProd;
//    }

    int maxProduct(vector<int>& nums) {
        int maxProd = std::numeric_limits< int >::min();
        int leftProduct = 1;
        int rightProduct = 1;

        const int size = nums.size();
        for( int i = 0, j = size - 1; i < size; ++i, --j ) {
            leftProduct = leftProduct ? leftProduct * nums[ i ] : nums[ i ];
            rightProduct = rightProduct ? rightProduct * nums[ j ] : nums[ j ];

            maxProd = std::max( maxProd, std::max( leftProduct, rightProduct ) );
        }

        return maxProd;
    }
};
