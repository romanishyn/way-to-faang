/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#pragma once

#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::vector;

namespace V1 {
/*
 * Sliding window only grows or keep the same length, no need to decrease because we try to find maximum length of window (substring).
 * Also we don't decrease a maxFrequent, because we should find new maximum count of the same characters in current
 * new substring (we change right position on each iteration).
 * 1) Need keep track of count characters in current window
 * 2) If in current window need change more characters than it allows, we move forward our left index, and decrease count of this char in cur. substr.
 * 3) At the and of each iteration update maximum length
 *
 * Time (n)
 * Space (1), potentially we can reduce size of characterCounts to 26
 * */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int characterCounts[ 256 ] = {};
        int maxFrequent = 0;
        int maxLength = 0;

        for( int left = 0, right = 0; right < s.size(); ++right ) {
            ++characterCounts[ s[ right ] ];
            maxFrequent = std::max( maxFrequent, characterCounts[ s[ right ] ] );

            if( ( right - left + 1 ) - maxFrequent > k ) {
                --characterCounts[ s[ left ] ];
                ++left;
            }

            maxLength = std::max( maxLength, right - left + 1 );
        }

        return maxLength;
    }
};
} // namespace V1

