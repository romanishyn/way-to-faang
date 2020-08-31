/*
https://leetcode.com/problems/single-number-iii/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
XOR all numbers, call with variable n1xn2. Since in input nums only two num is different, n1xn2 contains a xor b.
Each bit 1 in n1xn2 means that a and b have different bits in this position. If take rightmost bit 1 and partition
all numbers into two groups by critiria bit 1 in this position, then in first group will be first number, in second
group second number.

N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = std::accumulate( nums.begin(), nums.end(), 0, std::bit_xor<int>{} );
        diff &= - diff; // get rightmost bit 1

        vector< int > result( 2 );
        for( int num : nums ) {
            if( num & diff )
                result[ 0 ] ^= num;
            else
                result[ 1 ] ^= num;
        }
        return result;
    }
};
} // namespace