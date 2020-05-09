/*
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/

#pragma once

#include <limits>
#include <vector>
#include <unordered_set>
#include <stack>

using std::vector;

class Solution {
public:
    using Grid = vector< vector< int > >;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if( matrix.empty() )
            return {};

        const int rows = matrix.size();
        const int columns = matrix[ 0 ].size();

        Grid pacific( rows, vector< int >( columns ) );
        Grid atlantic( rows, vector< int >( columns ) );

        for( int i = 0; i < rows; ++i ) {
            dfs( matrix, pacific, i, 0, std::numeric_limits< int >::min() );
            dfs( matrix, atlantic, i, columns - 1, std::numeric_limits< int >::min() );
        }

        for( int j = 0; j < columns; ++j ) {
            dfs( matrix, pacific, 0, j, std::numeric_limits< int >::min() );
            dfs( matrix, atlantic, rows - 1, j, std::numeric_limits< int >::min() );
        }

        vector< vector< int > > result;
        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < columns; ++j ) {
                if( pacific[ i ][ j ] && atlantic[ i ][ j ] )
                    result.push_back( { i, j } );
            }
        }

        return result;
    }

    void dfs( const Grid& matrix, Grid& ocean, int i, int j, int prevValue ) {
        if( i < 0 || i >= matrix.size() || j < 0 || j >= matrix[ 0 ].size() )
            return;
        if( ocean[ i ][ j ] == 1 )
            return;
        if( prevValue > matrix[ i ][ j ])
            return;

        ocean[ i ][ j ] = 1;

        dfs( matrix, ocean, i - 1, j, matrix[ i ][ j ] );
        dfs( matrix, ocean, i + 1, j, matrix[ i ][ j ] );
        dfs( matrix, ocean, i, j - 1, matrix[ i ][ j ] );
        dfs( matrix, ocean, i, j + 1, matrix[ i ][ j ] );
    }
};
