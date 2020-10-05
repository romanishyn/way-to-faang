/*
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
*/

#include <string>
#include <array>

using std::string;

namespace {
/*
Sliding window

N - size of s

Time O(N)
Space O(1)
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::array< int, 256 > currWindow{};
        int distinctChar = 0;

        int maxSize = 0;

        for( int left = 0, right = 0; right < s.size(); ++right ) {
            if( currWindow[ s[ right ] ] == 0 )
                ++distinctChar;
            ++currWindow[ s[ right ] ];

            while( distinctChar > k ) {
                --currWindow[ s[ left ] ];
                if( currWindow[ s[ left ] ] == 0 )
                    --distinctChar;

                ++left;
            }

            const int currWindowSize = right - left + 1;
            maxSize = std::max( maxSize, currWindowSize );
        }

        return maxSize;
    }
};
} // namespace

namespace {
/*
If need remember not count of chars in window, but last position of char, we can map< char, idx >, or better soluion based on LRU

N - size of s
K - k

Time O(N*K)
Space O(K)
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        std::unordered_map< char, int > charToLastPos;

        auto comparator = []( const auto& lhs, const auto& rhs ) {
            return lhs.second < rhs.second;
        };

        int maxLength = 0;

        for( int left = 0, right = 0; right < s.size(); ++right ) {
            charToLastPos.insert_of_assign( s[ right ], right );

            if( charToLastPos.size() > k ) {
                auto it = std::min_element( charToLastPos.begin(), charToLastPos.end(), comparator );
                left = it->second + 1;
                charToLastPos.erase( it );
            }

            maxLength = std::max( maxLength, right - left + 1 );
        }

        return maxLength;
    }
};
} // namespace
