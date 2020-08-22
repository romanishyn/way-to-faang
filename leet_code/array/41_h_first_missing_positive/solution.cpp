/*
https://leetcode.com/problems/first-missing-positive/
*/

namespace {
/*
Use cycle sort, sort givent array, start sort from 1 to n. Then iterate over array  and check if indext don't equal value - 1 in this idx, return i + 1,
otherwise array if full e.g. [1,2,3,4] and return n + 1;

N - size of array

Time O(N)
Space O(1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int size = nums.size();

        int i = 0;
        while( i < size ) {
            if( nums[ i ] > 0 && nums[ i ] <= size && nums[ i ] != nums[ nums[ i ] - 1 ] )
                std::swap( nums[ i ], nums[ nums[ i ] - 1 ] );
            else
                ++i;
        }

        for( int i = 0; i < size; ++i ) {
            if( nums[ i ] != i + 1 )
                return i + 1;
        }

        return size + 1;
    }
};
} // namespace