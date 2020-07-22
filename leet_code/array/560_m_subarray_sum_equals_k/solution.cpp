/*
 * https://leetcode.com/problems/subarray-sum-equals-k/
 * */

#include <vector>
#include <unordered_map>

using std::vector;

namespace V1 {
/*
 * We cannon use Sliding Window approach
 * Instead we use cumulative sum or prefix sum
 *
 * N - length of nums
 *
 * Time (N)
 * Space (N)
 * */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;

        std::unordered_map< int/*prefix_sum*/, int /*frequency of pref_sum*/ > frequencyOfSum;
        ++frequencyOfSum[ 0 ]; // handle case when sum == k

        int prefixSum = 0;
        for( int x : nums ) {
            prefixSum += x;
            if( frequencyOfSum.count( prefixSum - k ) )
                counter += frequencyOfSum[ prefixSum - k ];

            ++frequencyOfSum[ prefixSum ];
        }

        return counter;
    }
};
} // namespace V1