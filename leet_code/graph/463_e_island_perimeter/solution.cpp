/*
 * https://leetcode.com/problems/island-perimeter/
 * */

#include <vector>
#include <stack>

using std::vector;

namespace V1 {
class Solution {
public:
    using Grid = vector<vector<int>>;

    int islandPerimeter(vector<vector<int>>& grid) {
        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                if( grid[ i ][ j ] == 1 )
                    return countPerimeter( grid, i, j );
            }
        }

        return 0;
    }

private:
    int countPerimeter( Grid& grid, int startRow, int startCol ) {
        constexpr int visitedIsland = 2;

        int perimeter = 0;
        std::stack< std::pair< int, int > > stack;
        stack.emplace( startRow, startCol );

        while( !stack.empty() ) {
            const auto [ row, col ] = stack.top();
            stack.top();

            if( row < 0 || row >= grid.size() || col < 0 || col >= grid[ 0 ].size() ) {
                ++perimeter;
                continue;
            }
            if( grid[ row ][ col ] ) {
                ++perimeter;
                continue;
            }
            if( grid[ row ][ col ] == visitedIsland ) {
                continue;
            }

            grid[ row ][ col ] = visitedIsland;

            stack.emplace( row - 1, col );
            stack.emplace( row + 1, col );
            stack.emplace( row, col + 1 );
            stack.emplace( row, col - 1 );
        }

        return perimeter;
    }
};
} // namespace V1

namespace V2 {
/*
 * NOT MINE:
 * the description of this problem implies there may be an "pattern" in calculating the perimeter of the islands.
and the pattern is islands * 4 - neighbours * 2, since every adjacent islands made two sides disappeared(as picture below).
the next problem is: how to find the neighbours without missing or recounting? i was inspired by the problem: https://leetcode.com/problems/battleships-in-a-board/
 *
 * +--+     +--+                   +--+--+
 * |  |  +  |  |          ->       |     |
 * +--+     +--+                   +--+--+
 * */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands{ 0 };
        int neighbors{ 0 };

        for( int i = 0; i < grid.size(); ++i ) {
            for( int j = 0; j < grid[ 0 ].size(); ++j ) {
                if( grid[ i ][ j ] == 1 ) {
                    ++islands;

                    if( i > 0 && grid[ i - 1 ][ j ] == 1 ) // count up neighbors
                        ++neighbors;
                    if( j > 0 && grid[ i ][ j - 1 ] == 1 ) // count left neighbors
                        ++neighbors;
                }
            }
        }

        return  islands * 4 - neighbors * 2;
    }
};
} // namespace V2