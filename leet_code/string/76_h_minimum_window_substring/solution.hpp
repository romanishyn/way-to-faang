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
/* 1) Use Sliding Window Technique: left and right to represent a window
 * 2) Move right pointer to find valid window
 * 3) When valid window is found, move left pointer to find minimum window
 * To check if window is valid we use map (char, count) for chars in t. And use counter to understand how many
 * characters found in current window. The key part is --requiredCharacters[ c ];. We decrease count for each
 * char from s. If character does not exist in t, it becomes negative. It also may become negative for
 * char from t, if this char is already in a window, and we leave the same char behind left pointer.
 * When we move left pointer, we increment count for each char, and if count became positive, it means that now
 * window is invalid (++counter).
 *
 * Time (2|s| + |t|) -> (|s| + |t|)
 * Space (1)
 * */
class Solution {
public:
    string minWindow(string s, string t) {
        int requiredCharacters[ 128 ] = {};
        for( char c : t )
            ++requiredCharacters[ c ];

        int left = 0;
        int right = 0;
        int counter = t.size();
        int startMinString = 0;
        int lengthMinString = std::numeric_limits< int >::max();

        while( right <= s.size() ) {
            const char c = s[ right ];
            if( requiredCharacters[ c ] > 0 )
                --counter;

            --requiredCharacters[ c ];

            while( counter == 0 ) {
                if( lengthMinString > right - left + 1 ) {
                    lengthMinString = right - left + 1;
                    startMinString = left;
                }

                ++requiredCharacters[ s[ left ] ];
                if( requiredCharacters[ s[ left ] ] > 0 )
                    ++counter;

                ++left;
            }

            ++right;
        }

        return lengthMinString == std::numeric_limits< int >::max() ? "" : s.substr( startMinString, lengthMinString );
    }
};
} // namespace V1

