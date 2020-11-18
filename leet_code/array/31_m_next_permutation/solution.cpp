/*
https://leetcode.com/problems/next-permutation/
*/

#include <vector>

using std::vector;

namespace {
/*
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3 -> 1 2 5 3 4
1 2 5 3 4
1 2 5 4 3

1 3 2 4 5

1 0 1 1

0 1 1 1
1 0 1 1

...
5 4 3 2 1 -> 1 2 3 4 5

N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int size = nums.size();
        int left = size - 2;

        while( left >= 0 && nums[ left ] >= nums[ left + 1 ] ) {
            --left;
        }

        if( left == -1 ) {
            reverse( nums, 0, size - 1 );
            // return false;
        }
        else {
            int pivot = size - 1;
            while( nums[ left ] >= nums[ pivot ] ) {
                --pivot;
            }
            std::swap( nums[ left ], nums[ pivot ] );
            reverse( nums, left + 1, size - 1 );
            // return true;
        }
    }

private:
    void reverse( std::vector< int >& nums, int left, int right ) {
        while( left < right ) {
            std::swap( nums[ left ], nums[ right ] );
            ++left;
            --right;
        }
    }
};
} // namespace
