/*
https://leetcode.com/problems/reorder-data-in-log-files/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of logs
L - size of max log

Time O(L*NlogN) - in case when all logs are letters, since we need sort them
Space O(L*N)
*/
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::vector< std::pair< std::string, std::string > > letterLogs;
        std::vector< std::string > digitLogs;

        for( const auto& log : logs ) {
            int pos = log.find_first_of( ' ' );

            if( std::isalpha( log.at( pos + 1 ) ) ) {
                auto id = log.substr( 0, pos );
                auto entry = log.substr( pos + 1 );

                letterLogs.emplace_back( id, entry );
            }
            else {
                digitLogs.push_back( log );
            }
        }

        auto comparator = []( const auto& pair1, const auto& pair2 ) {
            auto resEntry = pair1.second.compare( pair2.second );
            if( resEntry == 0 )
                return pair1.first < pair2.first;
            else
                return resEntry < 0;
        };
        std::sort( begin( letterLogs ), end( letterLogs ), comparator );

        std::vector< std::string > result;
        for( auto& [id, entry] : letterLogs )
            result.push_back( id + " " + entry );

        std::move( begin( digitLogs ), end( digitLogs ), std::back_inserter( result ) );

        return result;
    }
};
} //namespace

namespace {
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto comparator = []( const auto& log1, const auto& log2 ) {
            int pos1 = log1.find_first_of( ' ' );
            int pos2 = log2.find_first_of( ' ' );

            bool isAlpha1 = std::isalpha( log1.at( pos1 + 1 ) );
            bool isAlpha2 = std::isalpha( log2.at( pos2 + 1 ) );

            if( isAlpha1 && isAlpha2 ) {
                auto entry1 = log1.substr( pos1 + 1 );
                auto entry2 = log2.substr( pos2 + 1 );
                
                auto comparisonRes = entry1.compare( entry2 );
                if( comparisonRes == 0 ) {
                    auto id1 = log1.substr( 0, pos1 );
                    auto id2 = log2.substr( 0, pos2 );

                    return id1 < id2;
                }
                else {
                    return comparisonRes < 0;
                }
            }
            else if( !isAlpha1 && !isAlpha2 )
                return false;
            else
                return isAlpha1;
        };

        std::stable_sort( begin( logs ), end( logs ), comparator );
        return logs;
    }
};
} //namespace
