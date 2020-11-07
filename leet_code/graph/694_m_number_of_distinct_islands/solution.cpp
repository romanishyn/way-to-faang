/*
https://leetcode.com/problems/number-of-distinct-islands/
*/

#include <vector>
#include <unordered_set>

using std::vector;

namespace {
/*
L - length of island
N - grid.size
M - grid[ 0 ].size

Time O(N*M)
Space O(N*M)
*/
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        std::unordered_set< std::string > islands;
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                if( grid[ i ][ j ] == 1 ) {
                    std::string path;
                    recordIslandPath( grid, path, 's', i, j );
                    islands.insert( std::move( path ) );
                }
            }
        }
        return islands.size();
    }

    void recordIslandPath( vector<vector<int>>& grid, std::string& path, char label, int row, int col ) {
        if( row < 0 || row >= grid.size() || col < 0 || col >= grid[ 0 ].size() )
            return;
        if( grid[ row ][ col ] != 1 )
            return;

        grid[ row ][ col ] = 0;

        path.push_back( label );
        recordIslandPath( grid, path, 'u', row - 1, col );
        recordIslandPath( grid, path, 'd', row + 1, col );
        recordIslandPath( grid, path, 'l', row, col - 1 );
        recordIslandPath( grid, path, 'r', row, col + 1 );
        path.push_back( 'b' );
    }
};
} //namespace
