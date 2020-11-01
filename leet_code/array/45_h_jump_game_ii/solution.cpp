/*
https://leetcode.com/problems/jump-game-ii/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(1)
*/
/*
 0 1 2 3 4
[2,3,1,1,4]
       ^
 jumps // 2
 curr = 4
 next = 4

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        const int size = nums.size();
        if( size <= 1 )
            return 0;

        int jumps = 1;
        int currEnd = nums[ 0 ];
        int nextEnd = currEnd;

        for( int i = 1; i < size - 1; ++i ) {
            nextEnd = std::max( nextEnd, i + nums[ i ] );

            if( i == currEnd ) {
                ++jumps;
                currEnd = nextEnd;
            }
        }

        return jumps;
    }
};
} // namespace

namespace {
/*
N - size of nums

Time O(N)
Space O(1)
*/
/*
  0 1 2 3 4
 [2,3,1,1,4]
    ^
  curr = 2
  next = 2
  jumps = 1
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        const int size = nums.size();
        if( size <= 1 )
            return 0;

        int jumps = 1;
        int nextMaxPosition = nums[ 0 ];
        int currMaxPosition = nextMaxPosition;
        for( int i = 1; i < size; ++i ) {
            if( currMaxPosition < i ) {
                ++jumps;
                currMaxPosition = nextMaxPosition;
            }
            nextMaxPosition = std::max( nextMaxPosition, i + nums[ i ] );
        }

        return jumps;
    }
};
} // namespace
