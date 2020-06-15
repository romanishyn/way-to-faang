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
 * Here we are using Sliding Window approach. We move our front pointer (i) as far as we can without duplication
 * in current substring. When we find a duplicate character, we move our second pointer (j) until it's no longer duplicated.
 *
 * Time (2n) -> (n)
 * Space (1)
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool currentCharacters[ 256 ] = {};

        int maxLength = 0;
        int j = 0;
        for( int i = 0; i < s.size(); ++i ) {
            if( currentCharacters[ s[ i ] ] ) {
                for(; j < i; ++j ) {
                    currentCharacters[ s[ j ] ] = false;
                    if( s[ j ] == s[ i ] ) {
                        ++j;
                        break;
                    }
                }
            }

            maxLength = std::max( maxLength, i - j + 1 );
            currentCharacters[ s[ i ] ] = true;
        }

        return maxLength;
    }
};
} // namespace V1

namespace V2 {
/*
 * Using Sliding Window approach. In this solution we don't iterate second pointer (j - left) through all string, when we find duplication
 * in current "window", we just put it to the place of the same character (current) last found.
 *
 * Time (n)
 * Space (1)
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int index[ 256 ] = {};

        int maxLength = 0;

        for( int i = 0, j = 0; i < s.size(); ++i ) {
            j = std::max( j, index[ s[ i ] ] );
            index[ s[ i ] ] = i + 1;
            maxLength = std::max( maxLength, i - j + 1 );
        }

        return maxLength;
    }
};
} // namespace V2