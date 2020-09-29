/*
https://leetcode.com/problems/subarray-product-less-than-k/
*/

#include <vector>

using std::vector;

namespace {
/*
Sliding Window Approach

At the end of each iteratin we have new right position,
and if take size of current window we get number of subarrays with
this new numuber at position right.
If we have [1,2] and next new value is 3 -> [1,2,3], we will have
     [3]
   [2,3]
 [1,2,3]

To count how many subarray we can have in whole array, we can imagine computation
like adding new next value to current subarray, take lengt (right - left + 1), and add to the
previes sum.

N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if( k <= 1 )
            return 0;

        int left = 0;
        int prod = 1;

        int ans = 0;

        for( int right = 0; right < nums.size(); ++right ) {
            prod *= nums[ right ];
            while( prod >= k )
                prod /= nums[ left++ ];

            ans += right - left + 1;
        }

        return ans;
    }
};
} // namespace
