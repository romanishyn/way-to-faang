/*
https://leetcode.com/problems/image-overlap/
*/

#include <vector>

using std::vector;

namespace {
/*
N - A.size

Time O(N^4)
Space O(1)
*/
class Solution {
    using Matrix = vector<vector<int>>;
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int result = 0;

        const int size = A.size();
        for( int i = 0; i < size; ++i ) {
            for( int j = 0; j < size; ++j ) {
                result = std::max( {
                    result,
                    countOverlap( A, B, i, j ),
                    countOverlap( B, A, i, j )
                } );
            }
        }

        return result;
    }

private:
    int countOverlap( const Matrix& A, const Matrix& B, int x, int y ) {
        int counter = 0;
        
        const int size = A.size();
        for( int i = 0; i < size - x; ++i ) {
            for( int j = 0; j < size - y; ++j ) {
                if( A[ i ][ j ] == 1 && B[ i + x ][ j + y ] == 1 )
                    ++counter;
            }
        }

        return counter;
    }
};
} // namespace