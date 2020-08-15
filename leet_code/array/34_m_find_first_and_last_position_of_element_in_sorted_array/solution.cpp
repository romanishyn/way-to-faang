/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
Using lowerBound function find left bound and for the next value target + 1, then from right bound minus one.
If there is no target number, return values will be size of nums (end indecis)

N - length of nums

Time O(logN)
Space O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lowerBound( nums, target );
        int right = lowerBound( nums, target + 1 );

        if( left < right ) {
            return { left, right - 1 };
        }
        else {
            return { -1, -1 };
        }
    }

private:
    int lowerBound( const vector< int >& nums, int target ) {
        int left = 0;
        int right = nums.size() - 1;

        int ans = nums.size();
        while( left <= right ) {
            const int mid = left + ( right - left ) / 2;

            if( nums[ mid ] >= target ) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
} // namespace

namespace {
/*
If we are alowed to use build-in function we can use std::equal_range

N - length of nums

Time O(logN)
Space O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [ lower, upper ] = std::equal_range( nums.begin(), nums. end(), target );
        if( lower < upper ) {
            int lowerIdx = std::distance( nums.begin(), lower );
            int upperIdx = std::distance( nums.begin(), std::prev( upper ) );
            return { lowerIdx, upperIdx };
        }
        else {
            return { -1, -1 };
        }
    }
};
} // namespace
