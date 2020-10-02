/*
https://leetcode.com/problems/exclusive-time-of-functions/
*/

#include <stack>
#include <vector>

using std::vector;

namespace {
/*
Similar to "valid parentheses"

N - number of logs

Time O(N)
Space O(N)
*/
class Solution {
    struct Log {
        int id;
        int timestamp;
        std::string type;

        static Log fromString( const std::string& log ) {
            std::stringstream ss{ log };
            std::string id;
            std::string timestamp;
            std::string type;
            const char delim = ':';
            
            std::getline( ss, id, delim );
            std::getline( ss, type, delim );
            std::getline( ss, timestamp, delim );

            return Log{ std::stoi( id ), std::stoi( timestamp ), type };
        }
    };

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::vector< int > result( n );
        std::stack< Log > stack;

        for( const std::string& log : logs ) {
            Log entry = Log::fromString( log );
            if( entry.type == "start" ) {
                stack.push( entry );
            }
            else {
                Log topEntry = stack.top();
                stack.pop();
                int elapsed = entry.timestamp - topEntry.timestamp + 1;
                result[ entry.id ] += elapsed;

                if( ! stack.empty() ) {
                    result[ stack.top().id ] -= elapsed;
                }
            }
        }

        return result;
    }
};
} // namespace