/*
https://leetcode.com/problems/surrounded-regions/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>

using std::vector;

/*
[["O","O","O","O","X","X"]
,["O","O","O","O","O","O"]
,["O","X","O","X","O","O"]
,["O","X","O","O","X","O"]
,["O","X","O","X","O","O"]
,["O","X","O","O","O","O"]]

[["O","O","O","O","X","X"]
,["O","O","O","O","O","O"]
,["O","X","O","X","O","O"]
,["O","X","O","X","X","O"]
,["O","X","O","X","O","O"]
,["O","X","O","O","O","O"]]
 */

//class Solution {
//public:
//    using Matrix = std::vector<std::vector<bool>>;
//    using Stack = std::vector<std::pair<int, int>>;
//
//    void solve(vector<vector<char>>& board) {
//        if( board.empty() )
//            return;
//
//        const int rows = board.size();
//        const int columns = board[ 0 ].size();
//
//        Matrix visited( rows, std::vector< bool >( columns ) );
//        Stack stack;
//
//        for( int i = 0; i < rows; ++i ) {
//            for( int j = 0; j < columns; ++j ) {
//                if( !visited[ i ][ j ] && board[ i ][ j ] == 'O' ) {
//                    if( dfs( board, i, j, visited, stack ) ) {
//                        for( const auto & [row, col] : stack ) {
//                            board[ row][ col ] = 'X';
//                        }
//                    }
//
//                    stack.clear();
//                }
//            }
//        }
//    }
//
//private:
//    bool dfs( const vector<vector<char>>& board, int i, int j, Matrix& visited, Stack& stack ) {
//        if( i < 0 || i >= board.size() || j < 0 || j >= board[0].size() )
//            return false;
//        if( board[ i ][ j ] == 'X' )
//            return true;
//        if( visited[ i ][ j ] )
//            return true;
//
//        visited[ i ][ j ] = true;
//        stack.emplace_back( i, j );
//
//        bool res = dfs( board, i - 1, j, visited, stack );
//        res &= dfs( board, i + 1, j, visited, stack );
//        res &= dfs( board, i, j - 1, visited, stack );
//        res &= dfs( board, i, j + 1, visited, stack );
//
//        return res;
//    }
//};

class Solution {
public:
    void solve( vector< vector< char>> & board ) {
        if( board.empty() )
            return;

        const int rows = board.size();
        const int columns = board[ 0 ].size();

        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < columns; ++j ) {
                if( ( i == 0 || i == rows - 1 || j == 0 || j == columns - 1 ) && board[ i ][ j ] == 'O' ) {
                    std::queue< std::pair< int, int > > queue;
                    queue.push( { i , j } );

                    while( !queue.empty() ) {
                        const auto [ row, col ] = queue.front();
                        queue.pop();

                        if( row < 0 || row >= rows || col < 0 || col >= columns || board[ row ][ col ] != 'O' ) {
                            continue;
                        }

                        board[ row ][ col ] = 'B';
                        queue.push( { row - 1, col } );
                        queue.push( { row + 1, col } );
                        queue.push( { row, col - 1 } );
                        queue.push( { row, col + 1 } );
                    }
                }
            }
        }

        for( int i = 0; i < rows * columns; ++i ) {
            int row = i / columns;
            int col = i % columns;

            if( board[ row ][ col ] == 'B' )
                board[ row ][ col ] = 'O';
            else if( board[ row ][ col ] == 'O' )
                board[ row ][ col ] = 'X';
        }
    }
};
