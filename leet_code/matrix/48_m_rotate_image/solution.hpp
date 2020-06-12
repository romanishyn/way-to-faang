/*
https://leetcode.com/problems/rotate-image/
*/

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;

namespace V1 {
/*
 * top: [r1+i][c2]
 * right: [r2][c2-i]
 * bottom: [r2-i][c1]
 * left: [r1][c1+i]
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int c1 = 0;
        int c2 = matrix.size() - 1;
        int r1 = 0;
        int r2 = matrix.size() - 1;

        while( c1 < c2 && r1 < r2 ) {
            for( int i = 0; i < c2 - c1; ++i ) {
                int prev = matrix[ r1 ][ c1 + i ];
                int current = matrix[ r1 + i ][ c2 ];
                matrix[ r1 + i ][ c2 ] = prev;

                prev = current;
                current = matrix[ r2 ][ c2 - i ];
                matrix[ r2 ][ c2 - i ] = prev;

                prev = current;
                current = matrix[ r2 - i ][ c1 ];
                matrix[ r2 - i ][ c1 ] = prev;

                prev = current;
                matrix[ r1 ][ c1 + i ] = prev;
            }

            ++c1;
            --c2;
            ++r1;
            --r2;
        }
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int a = 0;
        int b = matrix.size() - 1;

        while( a < b ) {
            for( int i = 0; i < ( b - a ); ++i ) {
                std::swap( matrix[ a ][ a + i ], matrix[ a + i ][ b ] );
                std::swap( matrix[ a ][ a + i ], matrix[ b ][ b - i ] );
                std::swap( matrix[ a ][ a + i ], matrix[ b - i ][ a ] );
            }

            ++a;
            --b;
        }
    }
};
} // namespace V2

namespace V3 {
/*
 * First we transpose matrix and then reverse every row
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j ) {
                std::swap( matrix[ i ][ j ], matrix[ j ][ i ] );
            }
        }

        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n / 2; ++j ) {
                std::swap( matrix[ i ][ j ], matrix[ i ][ n - 1 - j ] );
            }
        }
    }
};
} // namespace V3

namespace V4 {
class Solution {
public:
    /*
     * In order to rotate a matrix on 90 degree, we need reverse every row and then transpose matrix (swap the symmetry)
     * Time (N) N - count of elements in matrix
     * Spase (1)
     * */
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for( int i = 0; i < n/2; ++i )
            std::swap( matrix[ i ], matrix[ n - 1 - i ] );

        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j ) {
                std::swap( matrix[ i ][ j ], matrix[ j ][ i ] );
            }
        }
    }

    /*
     * Reverse every column and then transpose matrix
     * Time (N) N - count of elements in matrix
     * Spase (1)
     * */
    void antiClockwiseRotate( vector<vector<int>>& matrix ) {
        const int n = matrix.size();

        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n/2; ++j ) {
                std::swap( matrix[ i ][ j ], matrix[ i ][ n - 1 -j ] );
            }
        }

        for( int i = 0; i < n; ++i ) {
            for( int j = i + 1; j < n; ++j ) {
                std::swap( matrix[ i ][ j ], matrix[ j ][ i ] );
            }
        }
    }
};
}
