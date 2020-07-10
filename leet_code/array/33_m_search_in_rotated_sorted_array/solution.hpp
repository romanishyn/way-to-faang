// https://leetcode.com/problems/search-in-rotated-sorted-array/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    // [4,5,6,7,8,1,2,3] target=8 expected=4
    // [3,5,1] target=3 expected=0
    // [4,5,6,7,0,1,2] target=0 expected=4
    // [] expected=-1

//    int search(vector<int>& nums, int target) {
//        if( nums.empty() )
//            return -1;
//
//        int start = 0;
//        int end = nums.size() - 1;
//
//        while( start < end ) {
//            const int mid = ( start + end ) >> 1;
//
//            if( nums[ mid ] == target )
//                return mid;
//
//            if( nums[ start ] < nums[ end ] ) {
//                if( target < nums[ mid ] )
//                    end = mid - 1;
//                else
//                    start = mid + 1;
//            }
//            else if( nums[ start ] > nums[ mid ] ) {
//                if( ( nums[ mid ] < target ) && ( target <= nums[ end ] ) )
//                    start = mid + 1;
//                else
//                    end = mid - 1;
//            } else {
//                if( ( nums[ start ] <= target ) && target < nums[ mid ] )
//                    end = mid - 1;
//                else
//                    start = mid + 1;
//            }
//        }
//
//        return nums[ start ] == target ? start : -1;
//    }

    int search(vector<int>& nums, int target) {
        if( nums.empty() )
            return -1;

        int start = 0;
        int end = nums.size() - 1;

        while( start < end ) {
            int mid = ( start + end ) >> 1;
            if( nums[ mid ] > nums[ end ] )
                start = mid + 1;
            else
                end = mid;
        }

        int shift = start;
        start = 0;
        end = nums.size() - 1;

        while( start <= end ) {
            const int mid = ( start + end ) >> 1;
            const int realMid = ( mid + shift ) % nums.size();

            if( nums[ realMid ] == target )
                return realMid;

            if( nums[ realMid ] > target )
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};

namespace V1 {
int search(vector<int>& nums, int target) {
    if( nums.empty() )
        return -1;

    int start = 0;
    int end = nums.size() - 1;

    while( start < end ) {
        int mid = ( start + end ) >> 1;
        if( nums[ mid ] > nums[ end ] )
            start = mid + 1;
        else
            end = mid;
    }

    int shift = start;
    start = 0;
    end = nums.size() - 1;

    while( start <= end ) {
        const int mid = ( start + end ) >> 1;
        const int realMid = ( mid + shift ) % nums.size();

        if( nums[ realMid ] == target )
            return realMid;

        if( nums[ realMid ] > target )
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}
} // namespace V1
