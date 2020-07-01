//https://leetcode.com/problems/3sum/

#pragma once

#include <vector>
#include <algorithm>

using std::vector;

namespace V1 {
/*
 * The main idea is to sort input array and then run through all elements in nums. We use current number to find two
 * other number which make total zero. For those two numbers, we move pointers left and right.
 * 1) Sort input array
 * 2) If the number is the same as the number before, we have used it as target already, continue.
 * 3) We always start left = i + 1 and right = size - 1
 * 4) If total is less than zero, we need it to be larger, so we move the left pointer
 * 5) If total is greater than zero, we need it to be smaller, so we move the right pointer
 * 6) If the total is zero, we've found triplet
 * 7) We need to move left and right pointer to the next different numbers, so we do not get repeating result
 *
 * Time (NlogN) + (N^2) -> (N^2)
 * Space (1) or size of result vector O(TBD)
 * */
class Solution {
public:
    vector< vector< int>> threeSum( vector< int > & nums ) {
        vector< vector< int>> result;
        if( nums.empty() )
            return result;

        std::sort( nums.begin(), nums.end() );

        const int size = nums.size();
        for( int i = 0; i < size - 2; ++i ) {
            const int target = -nums[ i ];
            int left = i + 1;
            int right = size - 1;

            while( left < right ) {
                if( target == nums[ left ] + nums[ right ] ) {
                    result.push_back( { nums[ i ], nums[ left ], nums[ right ] } );

                    const int rightVal = nums[ right ];
                    while( left < right && nums[ --right ] == rightVal ) {}
                } else if( target < nums[ left ] + nums[ right ] )
                    --right;
                else
                    ++left;
            }

            while( i < size - 2 && nums[ i ] == nums[ i + 1 ] )
                ++i;
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * Look at V1
 * */
class Solution {
public:
    vector< vector< int > > threeSum( vector< int > & nums ) {
        vector< vector< int > > result;

        std::sort( nums.begin(), nums.end() );

        const int size = nums.size();
        for( int i = 0; i < size - 2; ++i ) {
            if( i != 0 && nums[ i - 1 ] == nums[ i ] )
                continue;

            int left = i + 1;
            int right = size - 1;
            const int target = -nums[ i ];

            while( left < right ) {
                if( target == nums[ left ] + nums[ right ] ) {
                    const int leftValue = nums[ left ];
                    const int rightValue = nums[ right ];

                    result.push_back( { nums[ i ], leftValue, rightValue } );

                    while( left < right && leftValue == nums[ ++left ] );
                    while( left < right && rightValue == nums[ --right ] );
                }
                else if( target < nums[ left ] + nums[ right ] )
                    --right;
                else
                    ++left;
            }
        }

        return result;
    }
};
} // namespace V2
