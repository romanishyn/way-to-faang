/*
https://leetcode.com/problems/shortest-bridge/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
class Solution {
    using Positions = std::queue< std::pair< int, int > >;
    using Directions = std::vector< std::pair< int, int > >;

public:
    int shortestBridge(vector<vector<int>>& A) {
        const Directions directions{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        auto island = findAndFlipPositionsFirstIsland( A, directions );

        int bridges = 0;
        while( ! island.empty() ) {
            const int size = island.size();

            for( int i = 0; i < size; ++i ) {
                auto [ row, col ] = island.front();
                island.pop();

                for( auto [ x, y ] : directions ) {
                    int nRow = row + x;
                    int nCol = col + y;

                    if( nRow < 0 || nRow >= A.size() || nCol < 0 || nCol >= A[ 0 ].size() )
                        continue;
                    if( A[ nRow ][ nCol ] == 2 )
                        continue;
                    
                    if( A[ nRow ][ nCol ] == 1 )
                        return bridges;

                    island.emplace( nRow, nCol );
                    A[ nRow ][ nCol ] = 2;
                }
            }

            ++bridges;
        }

        return bridges;
    }

private:
    Positions findAndFlipPositionsFirstIsland( vector<vector<int>>& A, const Directions& directions ) {
        Positions positions;

        const int rows = A.size();
        const int cols = A[ 0 ].size();

        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < cols; ++j ) {
                if( A[ i ][ j ] == 1 ) {
                    fillAndFlipPositionsFirstIsland( A, positions, i, j );
                    return positions;
                }
            }
        }

        return positions;
    }

    void fillAndFlipPositionsFirstIsland( vector<vector<int>>& A, Positions& positions, int row, int col ) {
        if( row < 0 || row >= A.size() || col < 0 || col >= A[ 0 ].size() )
            return;
        if( A[ row ][ col ] == 0 || A[ row ][ col ] == 2 )
            return;

        positions.emplace( row, col );
        A[ row ][ col ] = 2;

        fillAndFlipPositionsFirstIsland( A, positions, row - 1, col );
        fillAndFlipPositionsFirstIsland( A, positions, row + 1, col );
        fillAndFlipPositionsFirstIsland( A, positions, row, col - 1);
        fillAndFlipPositionsFirstIsland( A, positions, row, col + 1);
    }
};
} // namespace