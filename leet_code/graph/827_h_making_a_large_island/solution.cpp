/*
https://leetcode.com/problems/making-a-large-island/
*/

#include <vector>
#include <unordered_map>

namespace {
/*
based on bfs

N - grid.size
grid.size == grid[ 0 ]

Time O(N^2)
Space O(N^2)
*/
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        std::unordered_map< int, int > islandSize;
        int islandLable = 2;

        const int n = grid.size();

        int maxSize = 0;

        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n; ++j ) {
                if( grid[ i ][ j ] == 1 ) {
                    int size = getIslandSize( grid, i, j, islandLable );
                    maxSize = std::max( maxSize, size );
                    islandSize[ islandLable ] = size;
                    ++islandLable;
                }
            }
        }

        std::vector< std::pair< int, int > > coords{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, - 1 } };

        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < n; ++j ) {
                if( grid[ i ][ j ] == 0 ) {
                    std::set< int > adjs;
                    for( const auto& [ x, y ] : coords ) {
                        int nR = i + x;
                        int nC = j + y;
                        if( nR < 0 || nR >= n || nC < 0 || nC >= n )
                            continue;
                        if( grid[ nR ][ nC ] < 2 )
                            continue;

                        adjs.insert( grid[ nR ][ nC ] );
                    }

                    int size = 1;
                    for( int label : adjs ) {
                        size += islandSize[ label ];
                    }

                    maxSize = std::max( maxSize, size );
                }

            }
        }

        return maxSize;
    }

private:
    int getIslandSize( vector<vector<int>>& grid, int i, int j, int islandLable ) {
        const int n = grid.size();
        if( i < 0 || i >= n || j < 0 || j >= n )
            return 0;
        if( grid[ i ][ j ] != 1 )
            return 0;
        
        grid[ i ][ j ] = islandLable;

        return  1
            +   getIslandSize( grid, i - 1, j, islandLable )
            +   getIslandSize( grid, i + 1, j, islandLable )
            +   getIslandSize( grid, i, j + 1, islandLable )
            +   getIslandSize( grid, i, j - 1, islandLable );
    }
};
} // namespace