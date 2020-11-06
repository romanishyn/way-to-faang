/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

#include <vector>

using std::vector;

namespace {
/*
N - rows
M - cols

Time O(N+M)
Space O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.empty() || matrix[ 0 ].empty() )
            return false;

        const int rows = matrix.size();
        const int cols = matrix[ 0 ].size();

        int i = 0;
        int j = cols - 1;
        while( i < rows && j >= 0 ) {
            if( matrix[ i ][ j ] == target )
                return true;

            if( target < matrix[ i ][ j ] )
                --j;
            else
                ++i;
        }

        return false;
    }
};
} // namespace