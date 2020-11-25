/*
https://leetcode.com/problems/asteroid-collision/
*/

#include <vector>
#include <deque>

using std::vector:

namespace {
/*
- left
+ right
- -
- +
+ - !
+ +

5 2 -3 -> 5
      

1 2 -3 -> -3



*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::deque< int > state;
        for( int ast : asteroids ) {
            state.push_back( ast );

            while( state.size() > 1 && meet( state[ state.size() - 2 ], state[ state.size() - 1 ] ) ) {
                int ast1 = state.back();
                state.pop_back();
                int ast2 = state.back();
                state.pop_back();

                if( std::abs( ast1 ) > std::abs( ast2 ) )
                    state.push_back( ast1 );
                else if( std::abs( ast1 ) < std::abs( ast2 ) )
                    state.push_back( ast2 );
            }
        }

        return { begin( state ), end( state ) };
    }

private:
    bool meet( int ast1, int ast2 ) {
        return ast1 > 0 && ast2 < 0;
    }
};
} // namespace

namespace {
/*
stack >
while ! empty && top > 0 && top <= -val
    stack.pop

if empty || top < 0 || val > 0
    stack.push( val )
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector< int > stack;

        for( int val : asteroids ) {
            while( ! stack.empty() && stack.back() > 0 && stack.back() < -val )
                stack.pop_back();

            if( stack.empty() || stack.back() < 0 || val > 0 )
                stack.push_back( val );
            else if( val < 0 && stack.back() == -val )
                stack.pop_back();
        }

        return stack;
    }
};
} // namespace
