/*
https://leetcode.com/problems/rotting-oranges/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*

N - total size of grid (m*n)

Time O(N)
Space O(N)
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int columns = grid[ 0 ].size();

        int freshOranges = 0;
        std::queue< std::pair< int, int > > rottenOranges;

        for( int i = 0; i < rows; ++i ) {
            for( int j = 0; j < columns; ++j ) {
                if( grid[ i ][ j ] == 1 )
                    ++freshOranges;
                else if( grid[ i ][ j ] == 2 )
                    rottenOranges.emplace( i, j );
            } 
        }

        std::array< std::pair< int, int >, 4 > directions{ std::pair{ -1, 0 }, std::pair{ 0, 1 }, std::pair{ 1, 0 }, std::pair{ 0, - 1 } };

        int minutes = 0;
        while( !rottenOranges.empty() && freshOranges ) {
            const int levelSize = rottenOranges.size();
            
            for( int i = 0; i < levelSize; ++i ) {
                auto [ x, y ] = rottenOranges.front();
                rottenOranges.pop();

                for( const auto& direction: directions ) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;

                    if( nextX < 0 || nextX >= rows || nextY< 0 || nextY >= columns )
                        continue;
                    if( grid[ nextX ][ nextY ] != 1 )
                        continue;

                    --freshOranges;
                    
                    grid[ nextX ][ nextY ] = 2;
                    rottenOranges.emplace( nextX, nextY );
                }
            }

            ++minutes;
        }

        return freshOranges ? -1 : minutes;
    }
};
} // namespace