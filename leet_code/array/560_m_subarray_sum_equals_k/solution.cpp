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

namespace {
/*
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = std::accumulate( nums.begin(), nums.end(), 0 );

        if( sum < k )
            return 0;

        std::vector< std::vector< int > > dp( nums.size(), std::vector< int >( sum + 1 ) );
        for( int i = 0; i < dp.size(); ++i )
            dp[ i ][ 0 ] = 1;

        if( nums[ 0 ] <= sum )
            dp[ 0 ][ nums[ 0 ] ] = 1;

        for( int i = 1; i < dp.size(); ++i ) {
            for( int j = 1; j < dp[ 0 ].size(); ++j ) {
                dp[ i ][ j ] = dp[ i - 1 ][ j ];
                if( nums[ i ] <= j)
                    dp[ i ][ j ] += dp[ i - 1 ][ j - nums[ i ] ];
            }
        }

        int counter = 0;
        for( int j = dp[ 0 ].size(); j >= k; --j )

        return dp.back().back();
    }
};
} // namespace