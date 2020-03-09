//https://leetcode.com/problems/two-sum/

#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
//    int findMin(vector<int>& nums) {
//        int prev = nums[ 0 ];
//        const int size = nums.size();
//
//        for( int i = 1; i < size; ++i ) {
//            const int curr = nums[ i ];
//            if( curr < prev )
//                return curr;
//
//            prev = curr;
//        }
//
//        return nums[ 0 ];
//    }

//    int findMin(vector<int>& nums) {
//        std::sort( nums.begin(), nums.end() );
//
//        return nums[ 0 ];
//    }

//    int find( const vector<int> & v, int minIdx, int maxIdx ) {
//        if( maxIdx - minIdx == 1 )
//            return v[ minIdx ];
//
//        const int midIdx = ( minIdx + maxIdx ) / 2;
//
//        const int lVal = v[ minIdx ];
//        const int mVal = v[ midIdx ];
//        const int rVal = v[ maxIdx - 1 ];
//
//        if( lVal < mVal ) {
//            if( mVal > rVal )
//                return find( v, midIdx, maxIdx );
//            else
//                return find( v, minIdx, midIdx );
//        } else {
//            return find( v, minIdx + 1, midIdx + 1 );
//        }
//    }
//    int findMin(vector<int>& nums) {
//        return find( nums, 0, nums.size() );
//    }


    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while( left < right ) {
            if( nums[ left ] < nums[ right ] )
                return nums[ left ];

            const int mid = ( left + right ) / 2; // >> 1
            if( nums[ mid ] > nums[ right ] )
                left = mid + 1;
            else
                right = mid;
        }

        return nums[ left ];
    }
};
