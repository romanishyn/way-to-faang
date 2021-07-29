/*
https://leetcode.com/problems/maximal-square/
*/

#include <vector>

using std::vector;

namespace {
/*
Brute Force

N - number of rows
M - number of cols

Time O((N*M)^2)
Space O(1)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if( matrix.empty() || matrix[ 0 ].empty() )
            return 0;

        const int rows = matrix.size();
        const int cols = matrix[ 0 ].size();

        int maxArea = 0;

        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < cols; ++j ) {
                if( matrix[ i ][ j ] == '1' ) {
                    int currArea = 1;
                    int row = i + 1;
                    int col = j + 1;
                    bool found = true;
                    while( row < rows && col < cols && matrix[ row ][ col ] == '1' && found ) {
                        for( int ii = i; ii <= row; ++ii ) {
                            if( matrix[ ii ][ col ] == '0' ) {
                                found = false;
                                break;
                            }
                        }
                        for( int jj = j; jj <= col && found; ++jj ) {
                            if( matrix[ row ][ jj ] == '0' ) {
                                found = false;
                                break;
                            }
                        }

                        if( found )
                            ++currArea;

                        ++row;
                        ++col;
                    }
                    
                    maxArea = std::max( maxArea, currArea );
                }
            }
        }

        return maxArea*maxArea;
    }
};
} // namespace

namespace {
/*
DP

N - number of rows
M - number of cols

Time O(N*M)
Space O(N*M)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if( matrix.empty() || matrix[ 0 ].empty() )
            return 0;

        const int rows = matrix.size();
        const int cols = matrix[ 0 ].size();
        
        std::vector< std::vector< int > > dp( rows + 1, std::vector< int >( cols + 1 ) );

        int maxArea = 0;

        for( int i = 1; i <= rows; ++i ) {
            for( int j = 1; j <= cols; ++j ) {
                if( matrix[ i - 1 ][ j - 1 ] == '1' ) {
                    dp[ i ][ j ] = std::min( {
                            dp[ i ][ j - 1 ]
                        ,   dp[ i - 1 ][ j - 1 ]
                        ,   dp[ i - 1 ][ j ]
                    } ) + 1;
                    maxArea = std::max( maxArea, dp[ i ][ j ] );
                }
            }
        }

        return maxArea*maxArea;
    }
};
} // namespace

namespace {
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if( matrix.empty() || matrix[ 0 ].empty() )
            return 0;

        const int rows = matrix.size();
        const int cols = matrix[ 0 ].size();

        int maxArea = 0;

        std::vector< int > dp( 
        
        

        return maxArea*maxArea;
    }
};
} // namespace

namespace {
/*
TODO: DP Space O(N)
*/
} // namespace
