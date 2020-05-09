/*
https://leetcode.com/problems/number-of-islands/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <stack>

using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                if( grid[ i ][ j ] == '1' ) {
                    dfs( grid, i, j );
                    ++count;
                }
            }
        }

        return count;
    }

    void dfs( vector<vector<char>>& grid, int row, int column ) {
        if( row < 0 || row > grid.size() - 1 || column < 0 || column > grid[0].size() - 1 )
            return;
        if( grid[ row ][ column ] == '0' )
            return;

        grid[row][column] = '0';

        dfs( grid, row - 1, column );
        dfs( grid, row + 1, column );
        dfs( grid, row, column - 1 );
        dfs( grid, row, column + 1 );
    }
};
