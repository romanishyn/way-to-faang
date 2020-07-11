/*
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * */

#include <vector>
#include <string>
#include <array>

using std::vector;
using std::string;

namespace V1 {
/*
 * We are gonna use Sliding Window approach. We need consider each substring in s, with size equal to size of p.
 * And if all characters from current substring are equal to p, we remember start of substring in result vector.
 * Our goal is to match all the characters from map with the current window
 * Decrement the frequency of the each character( even non-matched), and if frequency gets zero increase counter to understand how many character matched.
 *
// * 1) Create map, where key is character of p and value is number of occurrences in pattern
// * 2) We need
 *
 * N - size of s
 * M - size of p
 *
 * Time (N + M), since we need create map it costs M, and iterate over all s
 * Space (N + M), create result vector N, auxiliary map takes M
 * */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> resultIndices;

        std::array< int, 126 > patterFrequency{};
        for( char c : p )
            ++patterFrequency[ c ];

        int counter = 0;
        int start = 0;

        for( int end = 0; end < s.size(); ++end ) {
            const char rightChar = s[ end ];
            --patterFrequency[ rightChar ];
            if( patterFrequency[ rightChar ] >= 0 )
                ++counter;

            if( end - start + 1 == p.size() ) {
                if( counter == p.size() )
                    resultIndices.push_back( start );

                const char leftChar = s[ start ];
                ++patterFrequency[ leftChar ];
                if( patterFrequency[ leftChar ] > 0 )
                    --counter;

                ++start;
            }
        }

        return resultIndices;
    }
};
} // namespace V1
