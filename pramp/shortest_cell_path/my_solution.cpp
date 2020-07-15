#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1 1 1
// 1 0 1
// 1 1 1


int shortestCellPath(const vector<vector<int>>& grid, int sr, int sc, int tr, int tc)
{
    const int rows = grid.size();
    const int columns = grid[ 0 ].size();

    vector< vector< bool > > visited( rows, vector< bool >( columns, false ) );
    visited[ sr ][ sc ] = true;

    std::queue< std::pair< int, int > > q; // row , col

    q.push( { sr, sc } );

    int steps = 0;

    while( !q.empty() ) {
        const int levelSize = q.size();

        for( int i = 0; i < levelSize; ++i ) {
            auto coord = q.front();
            q.pop();

            if( coord.first == tr && coord.second == tc )
                return steps;

            vector< vector< int > > direction = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, - 1 } };
            for( const auto& dir : direction ) {
                int row = coord.first + dir[ 0 ];
                int col = coord.second + dir[ 1 ];

                if( row < 0 || row >= rows || col < 0 || col >= columns )
                    continue;
                if( visited[ row ][ col ] || grid[ row ][ col ] == 0 )
                    continue;

                visited[ coord.first ][ coord.second ] = true;

                q.push( { row, col } );
            }
        }

        ++steps;
    }

    return -1;
    // your code goes here
}