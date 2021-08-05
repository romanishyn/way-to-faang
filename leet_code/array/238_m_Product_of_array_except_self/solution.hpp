/*
 * https://leetcode.com/problems/product-of-array-except-self/
 */

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
//    vector<int> productExceptSelf(vector<int>& nums) {
//        const int size = nums.size();
//
//        std::vector<int> output( size, 1 );
//
//        for( int i = 0; i < size; ++i ) {
//            for( int j = 0; j < size; ++ j ) {
//                if( i != j ) {
//                    output[ j ] *= nums[ i ];
//                }
//            }
//        }
//
//        return output;
//    }

//    vector<int> productExceptSelf(vector<int>& nums) {
//        const int size = nums.size();
//
//        std::vector<int> output( size );
//
//        int total = 1;
//
//        for( int x : nums )
//                total *= x;
//
//        for( int i = 0; i < size; ++i )
//                output[ i ] = total / nums[ i ];
//
//        return output;
//    }

//    vector<int> productExceptSelf(vector<int>& nums) {
//            const int size = nums.size();
//
//            std::vector<int> output( size, 0 );
//
//            int total = 1;
//
//            int zeroIdx = -1;
//
//            for( int i = 0; i < size; ++i ) {
//                const int x = nums[ i ];
//                if( x == 0 ) {
//                    if( zeroIdx != -1 )
//                        return output;
//
//                    zeroIdx = i;
//                }
//                else {
//                    total *= x;
//                }
//            }
//
//            if( zeroIdx != -1 ) {
//                output[ zeroIdx ] = total;
//                return output;
//            }
//
//            for( int i = 0; i < size; ++i ) {
//                output[ i ] = total / nums[ i ];
//            }
//
//            return output;
//    }

//    vector<int> productExceptSelf(vector<int>& nums) {
//        const int size = nums.size();
//
//        std::vector< int > output( size );
//        std::vector< int > left( size );
//        std::vector< int > right( size );
//
//        left[ 0 ] = 1;
//        for( int i = 1; i < size; ++i )
//            left[ i ] = left[ i - 1 ] * nums[ i - 1 ];
//
//        right[ size - 1 ] = 1;
//        for( int i = size - 2; i >= 0; --i  )
//            right[ i ] = right[ i + 1 ] * nums[ i + 1 ];
//
//        for( int i = 0; i < size; ++i )
//            output[ i ] = left[ i ] * right[ i ];
//
//       return output;
//    }

    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();

        std::vector< int > output( size );

        output[ 0 ] = 1;
        for( int i = 1; i < size; ++i )
            output[ i ] = output[ i - 1 ] * nums[ i - 1 ];

        int right = 1;
        for( int i = size - 1; i >= 0; --i ) {
            output[ i ] *= right;
            right *= nums[ i ];
        }

       return output;
    }
};

namespace {
/*
Time O(N)
Space O(1) - output array does not count as extra space for space complexity analisys.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = nums.size();
        
        std::vector< int > result( size, 1 );
        
        for( int i = 1; i < size; ++i ) {
            result[ i ] = result[ i - 1 ] * nums[ i - 1 ];
        }
        
        int rightProd = 1;
        for( int i = size - 1; i >= 0; --i ) {
            result[ i ] *= rightProd;
            rightProd *= nums[ i ];
        }
        
        return result;
    }
};
}
