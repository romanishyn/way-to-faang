/*
https://leetcode.com/problems/group-shifted-strings/
*/

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {
/*
N - number of strings
K - length of max string

Time O(N*K)
Space O(N)
*/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::unordered_map< std::string, std::vector< std::string > > keyToGroup;
        for( const auto& str : strings ) {
            keyToGroup[ toKey( str ) ].push_back( str );
        }

        std::vector< std::vector< std::string > > result;
        for( auto& [_, group] : keyToGroup ) {
            result.push_back( group );
        }

        return result;
    }

private:
    std::string toKey( const std::string& str ) {
        constexpr int alphaCount = 26;

        std::string key;
        const int shift = str[ 0 ] - 'a';
        for( int i = 1; i < str.size(); ++i ) {
            key += ( str[ i ] - str[ i - 1 ] + alphaCount ) % alphaCount;
            key += '#';
        }

        return key;
    }
};
} // namespace
