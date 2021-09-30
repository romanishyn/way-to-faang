/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector< int > result( nums.size() );

        int left = 0;
        int right = nums.size() - 1;
        int write = nums.size() - 1;

        while( left <= right ) {
            const int val = std::abs( nums[ left ] ) < std::abs( nums[ right ] ) ? nums[ right-- ] : nums[ left++ ];

            result[ write-- ] = val * val;
        }

        return result;
    }
};
} // namespace
