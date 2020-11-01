/*
https://leetcode.com/problems/analyze-user-website-visit-pattern/
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using std::vector;
using std::string;

namespace {
/*
1. Store all visits for each user in ascending order by timestamp: unordered_map< user_name, map< timestamp, website > >
2. Create map< tripset, frequency > tripsetFreq
3. Iterate over all user and generate all possible UNIQUE tripset, put tripset into tripsetFreq and keep track of max frequency
4. Find result in tripsetFreq based on maxFrequency, and choose better result based on lexicographical comparison
5. return result
*/
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        const int size = username.size();

        std::unordered_map< std::string, std::map< int, std::string > > userVisits;
        for( int i = 0; i < size; ++i ) {
            userVisits[ username[ i ] ][ timestamp[ i ] ] = website[ i ];
        }

        int maxFrequency = 0;
        std::map< std::vector< std::string >, int > tripsetFrequency;

        for( const auto& [ _, userVisit ] : userVisits ) {
            std::set< std::vector< std::string > > tripsets;

            for( auto it1 = begin( userVisit ); it1 != end( userVisit ); ++it1 ) {
                for( auto it2 = std::next( it1 ); it2 != end( userVisit ); ++it2 ) {
                    for( auto it3 = std::next( it2 ); it3 != end( userVisit ); ++it3 ) {
                        tripsets.insert( { it1->second, it2->second, it3->second } );
                    }
                }
            }

            for( auto& tripset : tripsets ) {
                maxFrequency = std::max(
                    maxFrequency,
                    ++tripsetFrequency[ std::move( tripset ) ]
                );
            }
        }

        std::vector< std::string > result;
        for( auto& [ tripset, freq ] : tripsetFrequency ) {
            if(     maxFrequency == freq
                && ( result.empty() || tripset < result  )
            ) {
                result = std::move( tripset );
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
N - size of one container
W - length of longest string in website

Time O(N^3*(W))
Space O(N)
*/
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        constexpr char delim = ' ';

        const int size = username.size();

        // TC(N*(U+NlogN+W)
        std::unordered_map< std::string, std::map< int, std::string > > userVisits;
        for( int i = 0; i < size; ++i ) {
            userVisits[ username[ i ] ][ timestamp[ i ] ] = website[ i ];
        }

        int maxFrequency = 0;
        std::unordered_map< std::string, int > tripsetFrequency;

        // TC(N^3*(W)), N^3 - number of tripsets
        for( const auto& [ _, userVisit ] : userVisits ) {
            std::unordered_set< std::string > tripsets;

            // TC(N^3*(W))
            for( auto it1 = begin( userVisit ); it1 != end( userVisit ); ++it1 ) {
                for( auto it2 = std::next( it1 ); it2 != end( userVisit ); ++it2 ) {
                    for( auto it3 = std::next( it2 ); it3 != end( userVisit ); ++it3 ) {
                        tripsets.insert( it1->second + delim + it2->second + delim + it3->second );
                    }
                }
            }

            // TC(N^3*(W))
            for( auto& tripset : tripsets ) {
                maxFrequency = std::max(
                    maxFrequency,
                    ++tripsetFrequency[ std::move( tripset ) ]
                );
            }
        }

        // TC(N^3)
        std::string possibleResult;
        for( auto& [ tripset, freq ] : tripsetFrequency ) {
            if(     maxFrequency == freq
                && ( possibleResult.empty() || tripset < possibleResult  )
            ) {
                possibleResult = std::move( tripset );
            }
        }

        return split( possibleResult, delim );
    }

private:
    std::vector< std::string > split( const std::string& str, char delim ) {
        std::vector< std::string > result;
        std::istringstream iss{ str };
        for( std::string token; std::getline( iss, token, delim ); ) {
            result.push_back( std::move( token ) );
        }
        return result;
    }
};
} // namespace
