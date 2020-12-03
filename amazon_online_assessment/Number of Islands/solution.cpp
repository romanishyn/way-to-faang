/*
https://leetcode.com/problems/number-of-islands/
*/

#include <vector>
#include <stack>

using std::vector;

namespace {
/*
M - rows
N - cols

Time O(M*N)
Space O(M*N)
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                if( grid[ i ][ j ] == '1' ) {
                    exploreIsland( grid, i, j );
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void exploreIsland( vector<vector<char>>& grid, int i, int j ) {
        std::stack< std::pair< int, int > > stack;
        stack.emplace( i, j );
        grid[ i ][ j ] = '0';

        const std::vector< std::pair< int, int > > coordinates{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        while( ! stack.empty() ) {
            auto [ row, col ] = stack.top();
            stack.pop();

            for( auto [ x, y ] : coordinates ) {
                int nRow = row + x;
                int nCol = col + y;

                if( nRow < 0 || nRow >= grid.size() || nCol < 0 || nCol >= grid[ 0 ].size() )
                    continue;
                if( grid[ nRow ][ nCol ] != '1' )
                    continue;

                stack.emplace( nRow, nCol );
                grid[ nRow ][ nCol ] = '0';
            }
        }
    }
};
} // namespace
