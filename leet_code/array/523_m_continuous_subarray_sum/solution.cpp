/*
https://leetcode.com/problems/continuous-subarray-sum/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
N - size of nums
K - k

Time O(N)
Space O(min(N,K))
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map< int, int > remainders;
        remainders.try_emplace( 0, -1 );

        int sum = 0;
        for( int i = 0; i < nums.size(); ++i ) {
            sum += nums[ i ];
            int remainder = k == 0 ? sum : sum % k;

            auto [it, _] = remainders.try_emplace( remainder, i );
            if( i - it->second >= 2 )
                return true;
        }

        return false;
    }
};
} // namespace