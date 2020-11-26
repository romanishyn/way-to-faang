/*
https://leetcode.com/problems/search-a-2d-matrix/
*/

#include <vector>

using std::vector;

namespace {
/*
N - matrix.size
M - matrix[ 0 ].size

Time O(log(N*M))
Space  O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.empty() || matrix[ 0 ].empty() )
            return false;

        const int rows = matrix.size();
        const int cols = matrix[ 0 ].size();

        int left = 0;
        int right = rows * cols - 1;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;

            int col = mid % cols;
            int row = mid / cols;

            if( matrix[ row ][ col ] == target )
                return true;

            if( matrix[ row ][ col ] < target )
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};
} // namespace
