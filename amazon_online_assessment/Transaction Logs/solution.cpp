/*
https://leetcode.com/discuss/interview-question/862600/
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <stringstream>

namespace {
class Solution {
public:
    std::vector< std::string > getFraudIds( const std::vector< std::string >& logs, int threshold ) {
        std::unordered_map< std::string, int > idFrequency;
        for( const auto& entry : logs ) {
            auto tokens = split( entry, ' ' );

            ++idFrequency[ tokens[ 0 ] ];
            if( tokens[ 0 ] != tokens[ 1 ] )
                ++idFrequency[ tokens[ 1 ] ];
        }

        std::vector< std::string > result;
        for( const auto& [id, freq] : idFrequency ) {
            if( freq >= threshold )
                result.push_back( id );
        }

        auto comparator = []( const auto& lhs, const auto& rhs ) {
            return std::stoi( lhs ) > std::stoi( rhs );
        };
        std::sort( begin( result ), end( result ), comparator );

        return result;
    }

private:
    std::vector< std::string > split( const std::string& str, char delim ) {
        std::vector< std::string > tokens;
        std::stringstream ss{ str };
        for( std::string token; std::getline( ss, token, delim ); ) {
            tokens.push_back( std::move( token ) );
        }
        return tokens;
    }
}; // class Solution

int main() {
    Solution solution;
    std::vector< std::string > logs = {
        "345366 89921 45",
        "029323 38239 23",
        "38239 345366 15",
        "029323 38239 77",
        "345366 38239 23",
        "029323 345366 13",
        "38239 38239 23"
    };
    for( const auto& id : solution.getFraudIds( logs, 3 ) )
        std::cout << id << " ";
    std::cout << std::endl;

    return 0;
}
} // namespace
