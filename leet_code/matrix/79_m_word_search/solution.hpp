/*
https://leetcode.com/problems/word-search/
*/

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;

namespace V1 {
/* DFS + backtracking problem
 * Find position which matching first latter of word, and then recursively check rest of word.
 * To avoid visiting the same cell more then once, change visited[row][col] to 'true' to mark it as visited
 * Then move to the next one character word and compare it to the current neighbors.
 * */
class Solution {
public:
    using Board = vector< vector< char > >;
    using Visited = vector< vector< bool > >;

    bool exist(vector< vector< char > >& board, string word) {
        Visited visited( board.size(), vector< bool >( board[ 0 ].size() ) );

        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board[ 0 ].size(); ++j ) {
                if( board[ i ][ j ] == word[ 0 ] ) {
                    if( dfs( board, visited, 0, word, i, j ) )
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs( const Board& board, Visited& visited, int idx, const std::string& word, int row, int col ) {
        if( idx == word.size() )
            return true;
        if( row < 0 || row >= board.size() || col < 0 || col >= board[ 0 ].size() )
            return false;
        if( visited[ row ][ col ] )
            return false;
        if( board[ row ][ col ] != word[ idx ] )
            return false;

        std::pair< int, int > directions[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        visited[ row ][ col ] = true;

        for( auto [ x, y ] : directions ) {
            if( dfs( board, visited, idx + 1, word, row + x, col + y ) )
                return true;
        }

        visited[ row ][ col ] = false;

        return false;
    }
};
} // namespace V1

namespace V2 {
/* DFS + backtracking problem
 * Find position which matching first latter of word, and then recursively check rest of word.
 * To avoid visiting the same cell more then once, change board[row][col] to ' ' to mark it as visited
 * Then move to the next one character word and compare it to the current neighbors.
 */
class Solution {
public:
    using Board = vector< vector< char > >;

    bool exist(vector< vector< char > >& board, string word) {
        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board[ 0 ].size(); ++j ) {
                if( board[ i ][ j ] == word[ 0 ] ) {
                    if( dfs( board, 0, word, i, j ) )
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs( Board& board, int idx, const std::string& word, int row, int col ) {
        if( idx == word.size() )
            return true;
        if( row < 0 || row >= board.size() || col < 0 || col >= board[ 0 ].size() )
            return false;
        if( board[ row ][ col ] != word[ idx ] )
            return false;

        std::pair< int, int > directions[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        const char temp = board[ row ][ col ];
        board[ row ][ col ] = ' ';

        for( auto [ x, y ] : directions ) {
            if( dfs( board, idx + 1, word, row + x, col + y ) )
                return true;
        }

        board[ row ][ col ] = temp;

        return false;
    }
};
} // namespace V2
