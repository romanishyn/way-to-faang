/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

#include <vector>

using std::vector;

namespace {
/*
Solution based on bucket sort
Good explanation: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/discuss/693600/C++-99-O(n)/598856

N - size of nums

Time (N)
Space O(1)
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector< int > buckets( 101 );
        for( int num : nums )
            ++buckets[ num ];
        for( int i = 1; i < buckets.size(); ++i )
            buckets[ i ] += buckets[ i - 1 ];

        std::vector< int > result( nums.size() );
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] != 0 )
                result[ i ] = buckets[ nums[ i ] - 1 ];
        }

        return result;
    }
};
} // namespace