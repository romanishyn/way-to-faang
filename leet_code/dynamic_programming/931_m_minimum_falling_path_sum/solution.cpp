/*
https://leetcode.com/problems/minimum-falling-path-sum/
*/

#include <vector>

using std::vector;

namespace {
/*
N - A.size
M - A[0].size

Time O(N*M)
Space O(1)
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int rows = A.size();
        const int cols = A[ 0 ].size();

        for( int i = 1;i < rows; ++i ) {
            for( int j = 0; j < cols; ++j ) {
                A[ i ][ j ] += std::min( {
                    A[ i - 1 ][ std::max( 0, j - 1 ) ],
                    A[ i - 1 ][ j ],
                    A[ i - 1 ][ std::min( cols - 1, j + 1 ) ]
                } );
            }
        }

        int result = A.back().back();
        for( int j = 0; j < cols - 1; ++j )
            result = std::min( result, A[ rows - 1 ][ j ] );

        return result;
    }
};
} // namespace
