/*
https://leetcode.com/problems/n-queens/
*/

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {
/*
N - n

Time O(N^N) - ?
Space O(N)
*/
class Solution {
    std::vector< int > rows;
    std::vector< int > cols;
    int N = 0;

    using Result = std::vector< std::vector< std::string > >;

public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        rows.resize( N, -1 );
        cols.resize( N, -1 );

        Result result;
        solveNQueens( result, 0 );
        return result;
    }

private:
    void solveNQueens( Result& result, int rowIdx ) {
        if( rowIdx == N ) {
            addResult( result );
            return;
        }

        for( int colIdx = 0; colIdx < N; ++colIdx ) {
            if( canPlace( rowIdx, colIdx ) ) {
                takePlace( rowIdx, colIdx );
                solveNQueens( result, rowIdx + 1);
                freePlace( rowIdx, colIdx );
            }
        }
    }

    void addResult( Result& result ) {
        std::vector< std::string > grid;
        for( int i = 0; i < N; ++i ) {
            std::string row( N, '.' );
            row[ rows[ i ] ] = 'Q';
            grid.push_back( std::move( row ) );
        }
        result.push_back( std::move( grid ) );
    }

    bool canPlace( int rowIdx, int colIdx ) {
        if( cols[ colIdx ] != -1 )
            return false;

        for( int i = rowIdx - 1, count = 1; i >= 0; --i, ++count ) {
            if(     ( rows[ i ] == colIdx - count )
                ||  ( rows[ i ] == colIdx + count ) 
                )
                return false;
        }

        return true;
    }

    void takePlace( int rowIdx, int colIdx ) {
        rows[ rowIdx ] = colIdx;
        cols[ colIdx ] = rowIdx;
    }

    void freePlace( int rowIdx, int colIdx ) {
        rows[ rowIdx ] = -1;
        cols[ colIdx ] = -1;
    }
};
} // namespace

namespace {
/*
N - n

Time O(N!)
Space O(N)
*/
class Solution {
    std::vector< int > cols;
    std::vector< int > diagonals;
    std::vector< int > antidiagonals;

    using Grid = std::vector< std::string >;
    using Results = std::vector< Grid >;

public:
    vector<vector<string>> solveNQueens(int n) {
        Results results;
        Grid grid( n, std::string( n, '.' ) );

        cols.resize( n, 0 );
        diagonals.resize( 2*n - 1, 0 );
        antidiagonals.resize( 2*n - 1, 0 );

        solveNQueens( results, grid, 0, n );

        return results;
    }

private:
    void solveNQueens( Results& results, Grid& grid, int rowIdx, int size ) {
        if( rowIdx == size ) {
            results.push_back( grid );
        }
        else {
            for( int colIdx = 0; colIdx < size; ++colIdx ) {
                if( canPlace( colIdx, rowIdx, grid ) ) {
                    takePlace( colIdx, rowIdx, grid );
                    solveNQueens( results, grid, rowIdx + 1, size );
                    freePlace( colIdx, rowIdx, grid );
                }
            }
        }
    }

    bool canPlace( int colIdx, int rowIdx, const Grid& grid ) {
        int ans = cols[ colIdx ] + diagonals[ rowIdx + colIdx ] + antidiagonals[ grid.size() - 1 - rowIdx + colIdx ];
        return ans == 0;
    }

    void takePlace( int colIdx, int rowIdx, Grid& grid ) {
        cols[ colIdx ] = 1;
        diagonals[ rowIdx + colIdx ] = 1;
        antidiagonals[ grid.size() - 1 - rowIdx + colIdx ] = 1;

        grid[ rowIdx ][ colIdx ] = 'Q';
    }

    void freePlace( int colIdx, int rowIdx, Grid& grid ) {
        cols[ colIdx ] = 0;
        diagonals[ rowIdx + colIdx ] = 0;
        antidiagonals[ grid.size() - 1 - rowIdx + colIdx ] = 0;

        grid[ rowIdx ][ colIdx ] = '.';
    }
};
} // namespace

namespace {
/*
Solution above is better than this one
*/
class Solution {
    std::vector< bool > rows;
    std::vector< bool > cols;
    std::vector< bool > diagonal;
    std::vector< bool > anti_diagonal;
    int size;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        rows = std::vector< bool >( n );    
        cols = std::vector< bool >( n );
        diagonal = std::vector< bool >( n + n - 1 );
        anti_diagonal = std::vector< bool >( n + n - 1 );
        size = n;
        
        vector<vector<string>> result;
        vector<string> board( n, std::string( n, '.' ) );
        solveNQueens( result, board, 0 );
        
        return result;
    }
    
private:
    void solveNQueens( vector<vector<string>>& result, vector<string>& board, int row ) {
        if( row == size ) {
            result.push_back( board );
        }
        else {
            for( int j = 0; j < size; ++j ) {
                if( canTakePlace( row, j ) ) {
                    takePlace( row, j );
                    board[ row ][ j ] = 'Q';
                    solveNQueens( result, board, row + 1 );
                    freePlace( row, j );
                    board[ row ][ j ] = '.';
                }
            }
        }
    }
    
    bool canTakePlace( int i, int j ) {
        return !( rows[ i ] || cols[ j ] || diagonal[ i + j ] || anti_diagonal[ size - 1 - i + j ] );
    }
    
    void takePlace( int i, int j ) {
        rows[ i ] = true;
        cols[ j ] = true;
        diagonal[ i + j ] = true;
        anti_diagonal[ size - 1 - i + j ] = true;
    }
    
    void freePlace( int i , int j ) {
        rows[ i ] = false;
        cols[ j ] = false;
        diagonal[ i + j ] = false;
        anti_diagonal[ size - 1 - i + j ] = false;
    }
 };
}
