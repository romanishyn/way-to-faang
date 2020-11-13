/*
https://leetcode.com/problems/majority-element/
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
    int majorityElement(vector<int>& nums) {
        int number = nums[ 0 ];
        int count = 1;

        for( int i = 1; i< nums.size(); ++i ) {
            if( number == nums[ i ] )
                ++count;
            else
                --count;

            if( count == 0 ) {
                number = nums[ i ];
                count = 1;
            }
        }

        return number;
    }
};
} // namespace
