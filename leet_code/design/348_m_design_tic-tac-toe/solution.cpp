/*
https://leetcode.com/problems/design-tic-tac-toe/
*/

#include <vector>

namespace {
/*
N - size of side

Time O(N)
Space O(N)
*/
class TicTacToe {
    // pair< count, playerId > , default < 0, 0 >
    struct Line {
        int count{ 0 };
        int player{ 0 };
    };

    const int n;
    std::vector< Line > horizontal;
    std::vector< Line > vertical;
    Line diogonal45;
    Line diogonal135;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n )
    :   n( n )
    ,   horizontal( n )
    ,   vertical( n) 
    {
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if( horizontal[ row ].player == 0 )
            horizontal[ row ].player = player;
        if(  horizontal[ row ].player == player && ++horizontal[ row ].count == n )
            return player;

        if( vertical[ col ].player == 0 )
            vertical[ col ].player = player;
        if( vertical[ col ].player == player && ++vertical[ col ].count == n )
            return player;

        if( row + col == n - 1 ) {
            if( diogonal135.player == 0 )
                diogonal135.player = player;
            if( diogonal135.player == player && ++diogonal135.count == n )
                return player;
        }

        if( ( n - row ) + col == n ) {
            if( diogonal45.player == 0 )
                diogonal45.player = player;
            if( diogonal45.player == player && ++diogonal45.count == n )
                return player;
        }

        return 0;
    }
};
} // namespace

namespace {
/*
LC: TLE

N - size of side

Time O(N)
Space O(N^2)
*/
class TicTacToe {
    const int n;
    std::vector< std::vector< int > > board;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    :   n( n )
    ,   board( n, std::vectro< int >( n ) )
    {
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[ row ][ col ] = player;

        if(     checkHorizontal( row, player )
            ||  checkVertical( col, player )
            ||  checkDiogonal( player )
            || checkAntiDiogonal( player )
        )
            return player;

        return 0;
    }
    
private:
    bool checkHorizontal( int row, int player ) {
        for( int j = 0; j < n; ++j ) {
            if( board[ row ][ j ] != player )
                return 0;
        }
        return player;
    }

    bool checkVertical( int col, int player ) {
        for( int i = 0; i < n; ++i ) {
            if( board[ i ][ col ] != player )
                return 0;
        }
        return player;
    }

    bool checkDiogonal( int player ) {
        for( int idx = 0; idx < n; ++idx ) {
            if( board[ idx ][ idx ] != player )
                return 0;
        }
        return player;
    }

    bool checkAntiDiogonal( int player ) {
        for( int idx = n - 1; idx >= 0; -idx ) {
            if( board[ idx ][ n - idx ] != player )
                return 0;
        }
        return player;
    }
};
} // namespace

namespace {
class TicTacToe {
    const int n;
    int diagonal{ 0 };
    int antiDiagonal{ 0 };
    std::vector< int > rows;
    std::vector< int > cols;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    :   n( n )
    ,   rows( n )
    ,   cols( n )
    {
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int step = player == 1 ? 1 : -1;
        int targetCount = player == 1 ? n : -n;

        rows[ row ] += step;
        cols[ col ] += step;

        if( n - row + col == n )
        //if( row == col )
            diagonal += step;
        if( row + col + 1 == n )
            antiDiagonal += step;

        if(     rows[ row ] == targetCount
            ||  cols[ col ] == targetCount
            ||  diagonal == targetCount
            ||  antiDiagonal == targetCount
        )
            return player;

        return 0;
    }
};
} // namespace
