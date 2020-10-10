/*
https://leetcode.com/problems/longest-continuous-increasing-subsequence/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if( nums.empty() )
            return 0;

        int maxLength = 1;
        int currLength = 1;
        for( int i = 1; i < nums.size(); ++i ) {
            if( nums[ i - 1 ] < nums[ i ] )
                ++currLength;
            else
                currLength = 1;

            maxLength = std::max( maxLength, currLength );
        }

        return maxLength;
    }
};
} // namespace

namespace {
/*
Sliding Window Approach

N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if( nums.empty() )
            return 0;

        int maxLength = 0;
        for( int left = 0, right = 0; right < nums.size(); ++right ) {
            if( right > 0 && nums[ right - 1 ] >= nums[ right ] )
                left = right;

            maxLength = std::max( maxLength, right - left + 1 );
        }

       return maxLength;
    }
};
} // namespace
