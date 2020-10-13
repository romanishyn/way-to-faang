/*
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size nums

Time O(N)
Space O(N)
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int size = nums.size();

        std::vector< int > prefixSum{ 0 };
        for( int num : nums )
            prefixSum.push_back( prefixSum.back() + num );

        int maxSum = -1;

        std::vector< int > posLeft( size );
        for( int i = 0; i <= size - k; ++i ) {
            if( prefixSum[ i + k ] - prefixSum[ i ] > maxSum ) {
                maxSum = prefixSum[ i + k ] - prefixSum[ i ];
                posLeft[ i ] = i;
            }
            else {
                posLeft[ i ] = posLeft[ i - 1 ];
            }
        }

        maxSum = -1;

        std::vector< int > posRight( size );
        for( int i = size - k; i >= 0; --i ) {
            if( prefixSum[ i + k ] - prefixSum[ i ] >= maxSum ) {
                maxSum = prefixSum[ i + k ] - prefixSum[ i ];
                posRight[ i ] = i;
            }
            else {
                posRight[ i ] = posRight[ i + 1 ];
            }
        }

        maxSum = -1;

        std::vector< int > result( 3 );
        for( int i = k; i <= size - k - k; ++i ) {
            int l = posLeft[ i - k ];
            int r = posRight[ i + k ];

            int leftSum = prefixSum[ l + k ] - prefixSum[ l ];
            int midSum = prefixSum[ i + k ] - prefixSum[ i ];
            int rightSum = prefixSum[ r + k ] - prefixSum[ r ];
            if( leftSum + midSum + rightSum > maxSum ) {
                maxSum = leftSum + midSum + rightSum;
                result = { l, i, r };
            }
        }

        return result;
    }
};
} // namespace
