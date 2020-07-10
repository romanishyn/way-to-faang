/*
 * https://leetcode.com/problems/move-zeroes/
 * */

namespace V1 {
/*
 * Solution similar to std::remove algorithm.
 * We are gonna use 2 pointers approach, call them first and last.
 * We need find first zero value, and remember place in first, then initialise last with first + 1.
 * Iterate through array from last to the end. Each time when we encounter non-zero value, we
 * swap value where is first and last point, and increment first. This logic garantee follows invarians:
 *   - before first point all elements are non-zer
 *   - all elements between first and last pointers are zero
 *
 * N - number of elements in the input vector
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = find( nums, 0 );

        for( int last = first + 1; last < nums.size(); ++last ) {
            if( nums[ last ] != 0 )
                std::swap( nums[ first++ ], nums[ last ] );
        }
    }

    int find( const vector< int >& nums, int value ) {
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] == value )
                return i;
        }

        return nums.size();
    }
};
} // namespace V1
