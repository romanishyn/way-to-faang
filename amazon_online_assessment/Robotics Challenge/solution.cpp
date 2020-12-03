/*
https://leetcode.com/discuss/interview-question/806503/
*/

#include <string>
#include <vector>

namespace {
class Solution {
public:
    int totalScore( int /*num*/, const std::vector< std::string >& ops ) {
        std::vector< int > result;
        for( const auto& op : ops ) {
            if( op == "+" ) {
                if( result.size() >= 2 )
                    result.push_back( result[ result.size() - 1] + result[ result.size() - 2 ] );
            }
            else if( op == "X" ) {
                if( result.size() >= 1 )
                    result.push_back( result.back() * 2 );
            }
            else if( op == "Z" ) {
                if( result.size() >= 1 )
                    result.pop_back();
            }
            else {
                result.push_back( std::stoi( op ) );
            }
        }

        return std::accumulate( begin( result ), end( result ), 0 );
    }
};

int main() {
    Solution sol;

    assert( sol.totalScore( 8, { "5", "-2", "4", "Z", "X", "9", "+", "+" } ) == 27 );
    assert( sol.totalScore( 4, { "1", "2", "+", "Z" } ) == 3 );

    return 0;
}
} // namespace
