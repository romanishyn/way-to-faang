/*
https://leetcode.com/problems/majority-element-ii/
*/

#include <vector>

using std::vector;

namespace {
/*
Boyer-Moore Voting Algorithm


N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1;
        int candidate2 = -1;

        int count1 = 0;
        int count2 = 0;
        for( int num : nums ) {
            if( candidate1 == num ) {
                ++count1;
            }
            else if( candidate2 == num ) {
                ++count2;
            }
            else if( count1 == 0 ) {
                candidate1 = num;
                count1 = 1;
            }
            else if( count2 == 0 ) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                --count1;
                --count2;
            }
        }

        count1 = 0;
        count2 = 0;
        for( int num : nums ) {
            if( candidate1 == num )
                ++count1;
            else if( candidate2 == num )
                ++count2;
        }

        std::vector< int > result;
        if( count1 > nums.size() / 3 )
            result.push_back( candidate1 );
        if( count2 > nums.size() / 3 )
            result.push_back( candidate2 );

        return result;
    }
};
} // namespace
