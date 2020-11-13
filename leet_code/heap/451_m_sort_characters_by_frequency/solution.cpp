/*
https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include <string>
#include <unordered_map>

using std::string;

namespace {
/*
Bucket sort

N - size of s

Time O(N)
Space O(N)
*/
class Solution {
public:
    string frequencySort(string s) {
        int maxFreq = 0;
        std::unordered_map< char, int > charFreq;
        for( char ch : s ) {
            maxFreq = std::max( maxFreq, ++charFreq[ ch ] );
        }

        std::vector< std::vector< char > > buckets( maxFreq + 1 );
        for( auto [ch, freq] : charFreq ) {
            buckets[ freq ].push_back( ch );
        }

        std::string result;
        for( int i = buckets.size() - 1; i > 0; --i ) {
            for( char ch : buckets[ i ] ) {
                result.append( i, ch );
            }
        }

        return result;
    }
};
} // namespace
