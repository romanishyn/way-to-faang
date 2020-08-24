/*
https://leetcode.com/problems/the-maze/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
To find first posible way from start to destination we can use Breadth Frist Search. To prevent visiting the same
cell more than once, we can change value of visited value to 1. If we are not allowed to modify maze, we can create
helpler maze(copy of origin one).

N = total number of cells

Time O(N)
Space O(N)
*/
class Solution {
    using Coordinate = std::pair< int, int >;
    const std::vector< Coordinate > directions{ { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };

public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        const Coordinate target{ destination[ 0 ], destination[ 1 ] };

        std::queue< Coordinate > todo;
        todo.emplace( start[ 0 ], start[ 1 ] );
        maze[ start[ 0 ] ][ start[ 1 ] ] = 2;

        while( !todo.empty() ) {
            auto coord = todo.front();
            todo.pop();

            if( coord == target )
                return true;


            for( const auto& direction : directions ) {
                int x = coord.first + direction.first;
                int y = coord.second + direction.second;

                while (x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0) {
                    x += direction.first;
                    y += direction.second;
                }
                if (maze[x - direction.first][y - direction.second] != 2 ) {
                    maze[x - direction.first][y - direction.second] = 2;
                    todo.emplace( x - direction.first, y - direction.second );
                }
            }
        }

        return false;
    }
};
} // namespace