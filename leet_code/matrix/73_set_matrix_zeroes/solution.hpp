/*
https://leetcode.com/problems/two-city-scheduling/
*/

#pragma once

#include <vector>
#include <algorithm>


using std::vector;

namespace V1 {
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if( matrix.empty() )
            return;

        vector< bool > rows( matrix.size() );
        vector< bool > columns( matrix[ 0 ].size() );

        for( int i = 0; i < matrix.size(); ++i ) {
            for( int j = 0; j < matrix[ 0 ].size(); ++j ) {
                if( matrix[ i ][ j ] == 0 ) {
                    rows[ i ] = true;
                    columns[ j ] = true;
                }
            }
        }

        for( int i = 0; i < matrix.size(); ++i ) {
            for( int j = 0; j < matrix[ 0 ].size(); ++j ) {
                if( rows[ i ] || columns[ j ] )
                    matrix[ i ][ j ] = 0;
            }
        }
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    void setZeroes( vector< vector< int>> & matrix ) {
        if( matrix.empty() )
            return;

        const int rows = matrix.size();
        const int columns = matrix[ 0 ].size();

        bool rowSet = false;
        bool columnSet = false;

        for( int j = 0; j < columns; ++j ) {
            if( matrix[ 0 ][ j ] == 0 ) {
                rowSet = true;
                break;
            }
        }

        for( int i = 0; i < rows; ++i ) {
            if( matrix[ i ][ 0 ] == 0 ) {
                columnSet = true;
                break;
            }
        }

        for( int i = 1; i < rows; ++i ) {
            for( int j = 1; j < columns; ++j ) {
                if( matrix[ i ][ j ] == 0 ) {
                    matrix[ i ][ 0 ] = 0;
                    matrix[ 0 ][ j ] = 0;
                }
            }
        }

        for( int i = 1; i < rows; ++i ) {
            for( int j = 1; j < columns; ++j ) {
                if( matrix[ i ][ 0 ] == 0 || matrix[ 0 ][ j ] == 0 )
                    matrix[ i ][ j ] = 0;
            }
        }

        if( rowSet ) {
            for( int j = 0; j < columns; ++j )
                matrix[ 0 ][ j ] = 0;
        }

        if( columnSet ) {
            for( int i = 0; i < rows; ++i )
                matrix[ i ][ 0 ] = 0;
        }
    }
};
} // namespace V2
