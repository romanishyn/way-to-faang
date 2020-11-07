/*
https://leetcode.com/problems/design-snake-game/
*/

#include <vector>
#include <queue>
#include <unordered_set>

using std::vector;

namespace {
/*
W - weigth
H - height
N - size of food

Time O(1)
Space O(W*H + N)
*/
class SnakeGame {
    const int width;
    const int height;
    int foodIdx{ 0 };
    std::vector< std::vector< int > > food;
    std::queue< std::pair< int/*x*/, int/*y*/ > > snake;
    std::unordered_set< int > occupiedPositions;

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food)
    :   width{ width }
    ,   height{ height }
    ,   food{ food }
    {
        takePos( 0, 0 );
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto [x, y] = snake.back();

        if( direction == "U" )
            x -= 1;
        else if( direction == "L" )
            y -= 1;
        else if( direction == "R" )
            y += 1;
        else
            x += 1;

        if( foodIdx < food.size() && food[ foodIdx ][ 0 ] == x && food[ foodIdx ][ 1 ] == y ) {
            ++foodIdx;
        }
        else {
            popLastPos();
        }

        if( ! isValid( x, y ) ) {
            return -1; // game over;
        }

        takePos( x, y );

        return snake.size() - 1;
    }

private:
    void takePos( int x, int y ) {
        snake.emplace( x, y );
        occupiedPositions.insert( toNumber( x, y ) );
    }
    
    void popLastPos() {
        auto [x, y] = snake.front();
        snake.pop();
        occupiedPositions.erase( toNumber( x, y ) );
    }

    bool isValid( int x, int y ) {
        if( x < 0 || x >= height || y < 0 || y >= width )
            return false;
        if( occupiedPositions.count( toNumber( x, y ) ) )
            return false;
        else
            return true;
    }

    int toNumber( int x, int y ) {
        return width * x + y;
    }
};
} // namespace
