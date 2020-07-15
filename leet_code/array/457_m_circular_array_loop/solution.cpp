/*
 * https://leetcode.com/problems/circular-array-loop/
 * */

#include <vector>
#include <printf.h>

using std::vector;

namespace V1 {
/*
 * We can start from each index of the array to find cycle. If a number does not have a cycle we will move forward to the next element.
 *
 * Time (N^2)
 * Space (1)
 * */
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] == 0 )
                continue;

            int slow = i;
            int fast = i;
            const bool isForward = nums[ i ] > 0;

            do {
                slow = getNextIndex( isForward, nums, slow );
                fast = getNextIndex( isForward, nums, fast );

                if( fast != -1 )
                    fast = getNextIndex( isForward, nums, fast );
            } while( slow != -1 && fast != -1 && slow != fast );

            if( slow != -1 && slow == fast )
                return true;
        }

        return false;
    }

private:
    int getNextIndex( bool isForward, const vector<int>& nums, int idx ) {
        if( isForward != nums[ idx ] > 0 )
            return -1;

        // NOTE: wrap negative indices
        int nextIdx = ( idx + nums[ idx ] + nums.size() ) % nums.size();

        if( nextIdx == idx )
            return -1;

        return nextIdx;
    }
};
} // namespace V1

namespace V2 {
/*
 * We can start from each index of the array to find cycle. If a number does not have a cycle we will move forward to the next element.
 *
 * Time (N^2)
 * Space (1)
 * */
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        std::vector< bool > map (nums.size());

        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] == 0 )
                continue;

            int slow = i;
            int fast = i;
            const bool isForward = nums[ i ] > 0;

            do {
                slow = getNextIndex( isForward, nums, slow );
                fast = getNextIndex( isForward, nums, fast );

                if( fast != -1 )
                    fast = getNextIndex( isForward, nums, fast );
            } while( slow != -1 && fast != -1 && slow != fast );

            if( slow != -1 && slow == fast )
                return true;
        }

        return false;
    }

private:
    int getNextIndex( bool isForward, const vector<int>& nums, int idx ) {
        if( isForward != nums[ idx ] > 0 )
            return -1;

        // NOTE: wrap negative indices
        int nextIdx = ( idx + nums[ idx ] + nums.size() ) % nums.size();

        if( nextIdx == idx )
            return -1;

        return nextIdx;
    }
};
} // namespace V1