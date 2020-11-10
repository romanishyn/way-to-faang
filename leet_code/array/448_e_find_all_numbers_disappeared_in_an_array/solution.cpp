/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(1)

 0 1 2 3 4 5 6 7
[1,2,3,4,3,2,7,8]
           i
 j
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx = 0;
        while( idx < nums.size() ) {
            int j = nums[ idx ] - 1;
            if( nums[ idx ] != nums[ j ] )
                std::swap( nums[ idx ], nums[ j ] );
            else
                ++idx;
        }

        std::vector< int > result;
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] != i + 1 )
                result.push_back( i + 1 );
        }

        return result;
    }
};
} // namespace
