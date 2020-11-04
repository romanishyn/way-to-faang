/*
https://leetcode.com/problems/baseball-game/
*/

#include <vector>
#include <algorithms>

using std::vector;

namespace {
/*
N - size of ops

Time O(N)
Space O(N)
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        std::vector< int > scores;
        for( const auto& operation : ops ) {
            if( operation == "+" ) {
                scores.push_back( scores[ scores.size() - 1 ] + scores[ scores.size() - 2 ] );
            }
            else if( operation == "D" ) {
                scores.push_back( scores.back() * 2 );
            }
            else if( operation == "C" ) {
                scores.pop_back();
            }
            else {
                scores.push_back( std::stoi( operation ) );
            }
        }

        return std::accumulate( begin( scores ), end( scores ), 0 );
    }
};
} // namespace