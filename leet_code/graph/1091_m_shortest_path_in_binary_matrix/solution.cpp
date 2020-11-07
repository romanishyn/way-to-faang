/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
N - length of side

Time O(N^2)
Space O(N^2)

[[1,0,0]
,[1,1,0]
,[1,1,0]]
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int N = grid.size();
        if( grid[ 0 ][ 0 ] == 1 || grid[ N - 1 ][ N - 1] == 1 )
            return -1;

        auto seen = grid;
        std::queue< std::pair< int, int > > todo;
        todo.emplace( 0, 0 );
        seen[ 0 ][ 0 ] = 1;

        const std::vector< std::pair< int, int > > coordinations{ { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };
        int path = 1;
        while( ! todo.empty() ) {
            const int levelSize = todo.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto [row, col] = todo.front();
                todo.pop();

                if( row == N - 1 && col == N - 1 )
                    return path;

                for( auto [x, y] : coordinations ) {
                    x += row;
                    y += col;
                    if( x < 0 || x >= N || y < 0 || y >= N )
                        continue;
                    if( seen[ x ][ y ] )
                        continue;

                    seen[ x ][ y ] = 1;
                    todo.emplace( x, y );
                }
            }

            ++path;
        }

        return -1;
    }
};
} // namespace
