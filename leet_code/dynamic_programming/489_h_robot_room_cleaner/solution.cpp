/*
https://leetcode.com/problems/robot-room-cleaner/
*/


namespace {
/*

*/

  // This is the robot's control interface.
  // You should not implement it, or speculate about its implementation
  class Robot {
    public:
      // Returns true if the cell in front is open and robot moves into the cell.
      // Returns false if the cell in front is blocked and robot stays in the current cell.
      bool move();

      // Robot will stay in the same cell after calling turnLeft/turnRight.
      // Each turn will be 90 degrees.
      void turnLeft();
      void turnRight();

      // Clean the current cell.
      void clean();
  };

class Solution {
    using Visited = std::unordered_map< int, std::unordered_set< int > >;
public:
    void cleanRoom(Robot& robot) {
        Visited visited;
        dfs( robot, visited, 0, 0, 0 );
    }

private:
    void dfs( Robot& robot, Visited& visited, int x, int y, int direction ) {
        robot.clean();
        setVisited( visited, x, y );

        for( int i = 0; i < 4; ++i ) {
            int nextX = x;
            int nextY = y;
            switch( direction ) {
                case 0:
                    nextX -= 1;
                    break;
                case 90:
                    nextY += 1;
                case 180:
                    nextX += 1;
                case 270:
                    nextY -= 1;
                default:
                    break;
            }

            if( ! isVisited( visited, nextX, nextY ) && robot.move() ) {
                dfs( robot, visited, nextX, nextY, direction );
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }

            robot.turnRight();
            direction += 90;
            direction %= 360;
        }
    }

    bool isVisited( const Visited& visited, int x, int y ) {
        return visited.count( x ) && visited[ x ].count( y );
    }
    
    void setVisited( Visited& visited, int x, int y ) {
        visited[ x ].insert( y );
    }
};
} // namespace