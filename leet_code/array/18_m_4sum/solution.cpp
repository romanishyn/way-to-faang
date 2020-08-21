/*
https://leetcode.com/problems/4sum/
*/

#include <vector>

using std::vector;

namespace {
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::unordered_map< int, std::pair< int, int > > twoSums;

        const int size = nums.size();
        for( int i = 0; i < size - 1; ++i ) {
            for( int j = i + 1; j < size; ++j ) {
                
            }
        }
    }
};
} // namespace