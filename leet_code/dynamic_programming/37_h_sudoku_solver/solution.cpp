/*
 *https://leetcode.com/problems/sudoku-solver/
 * */

#include <vector>
#include <cmath>

using std::vector;

namespace V1 {
/*
 * Good explanation BtB SWE:https://www.youtube.com/watch?v=JzONv5kaPJM
 *
 * The idea is using a backtracking approach.
 *
 * We have tree keys of our solution:
 * Choice: on each recursion call if cell is empty we have to put in the cell value from 1 to 9. If it's possible
 *  then consider cell. If it doesn't work our, undo choice and move on to the next one.
 *  If all choices was considered and no one works out, return false.
 * Constrains: value from 1 to 9
 * Goal: fill each empty cells
 *
 * Time: O(1) or O(9^(N*N)) or O(9!^9)
 * Space: O(1) or O(N*N)
 * */
class Solution {

    using Board = std::vector< std::vector< char > >;

public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku( board, 0, 0 );
    }

private:
    bool solveSudoku( Board& board, int row, int col ) {
        const int N =  board.size();

        if( col == N ) {
            col = 0;
            ++row;

            if( row == N ) {
                return true;
            }
        }

        if( board[ row ][ col ] != '.' )
            return solveSudoku( board, row, col + 1 );

        for( int i = 1; i <= 9; ++i ) {
            board[ row ][ col ] = i + '0';
            if( isValid( board, row, col ) && solveSudoku( board, row, col + 1 ) )
                return true;
            board[ row ][ col ] = '.';
        }

        return false;
    }

    bool isValid( const Board& board, int row, int col ) {
        const char currVal = board[ row ][ col ];

        for( int i = 0; i < board.size(); ++i ) {
            if( i != row && board[ i ][ col ] == currVal )
                return false;
        }

        for( int j = 0; j < board[ 0 ].size(); ++j ) {
            if( j != col && board[ row ][ j ] == currVal )
                return false;
        }

        const int subBoxLength = std::sqrt( board.size() );
        const int leftTopRow = ( row / subBoxLength ) * subBoxLength;
        const int leftTopCol = ( col / subBoxLength ) * subBoxLength;

        for( int i = leftTopRow; i < leftTopRow + subBoxLength; ++i ) {
            for( int j = leftTopCol; j < leftTopCol + subBoxLength; ++j ) {
                if( i != row && j != col && board[ i ][ j ] == currVal )
                    return false;
            }
        }

        return true;
    }
};
} // namespace V1