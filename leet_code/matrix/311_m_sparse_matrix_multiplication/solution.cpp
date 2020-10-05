/*
https://leetcode.com/problems/sparse-matrix-multiplication/
*/

#include <vector>

using std::vector;

namespace {
/*
A[NxM] * B[MxK] = C[NxK]

Time O(N*M*K)
Space O(1)
*/
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int n = A.size();
        const int m = A[ 0 ].size();
        const int k = B[ 0 ].size();

        std::vector< std::vector< int > > result( n, std::vector< int >( k ) );
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < m; ++j ) {
                if( A[ i ][ j ] == 0 )
                    continue;
                for( int idx = 0; idx < k; ++idx ) {
                    result[ i ][ idx ] += A[ i ][ j ] * B[ j ][ idx ];
                }
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
Matrix compression.
Solution based on: https://leetcode.com/problems/sparse-matrix-multiplication/discuss/76150/Java-and-Python-Solutions-with-and-without-Tables/79622

A[NxM] * B[MxK] = C[NxK]

Time O(N*M*K)
Space O(1)
*/
class Solution {
    using SpareMatrix = std::unordered_map< int/*rowIdx*/, std::unordered_map< int/*colIdx*/, int/*val*/ > >;

public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const auto matrixA = compress( A );
        const auto matrixB = compress( B );

        std::vector< std::vector< int > > result( A.size(), std::vector< int >( B[ 0 ].size() ) );
        for( const auto& [ i, rowA ] : matrixA ) {
            for( const auto& [ j, valA ] : rowA ) {
                if( ! matrixB.count( j ) )
                    continue;

                for( const auto& [ k, valB ] : matrixB.at( j ) ) {
                    result[ i ][ k ] += valA * valB;
                }
            }
        }

        return result;
    }

private:
    SpareMatrix compress( const vector< vector< int > > & matrix ) {
        SpareMatrix spareMatrix;
        for( int i = 0; i < matrix.size(); ++i ) {
            for( int j = 0; j < matrix[ 0 ].size(); ++j ) {
                if( matrix[ i ][ j ] != 0 )
                    spareMatrix[ i ][ j ] = matrix[ i ][ j ];
            }
        }
        return spareMatrix;
    }
};
} // namespace
