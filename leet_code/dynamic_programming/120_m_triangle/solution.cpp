/*
https://leetcode.com/problems/triangle/
*/

#include <vector>

using std::vector;

namespace {
/*
DP

N - triangle.size

Time O(N^2)
Space O(1)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for( int i = 1; i < triangle.size(); ++i ) {
            for( int j = 0; j < triangle[ i ].size(); ++j ) {
                const int minVal = std::min(
                    triangle[ i - 1 ][ std::max( 0, j - 1 ) ],
                    triangle[ i - 1 ][ std::min( j, (int)triangle[ i - 1 ].size() - 1 ) ]
                );
                triangle[ i ][ j ] += minVal;
            }
        }

        int result = std::numeric_limits< int >::max();
        for( int num : triangle.back() )
            result = std::min( result, num );

        return result;
    }
};
} // namespace
