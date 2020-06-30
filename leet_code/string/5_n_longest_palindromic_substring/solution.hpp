/*
https://leetcode.com/problems/longest-palindromic-substring/
*/

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace V1 {
/*
 * Idea is to start from each center for even and odd length and expand around center. If current palindrome
 * longer than previous ones, updated start and maxLength. At the end return substirng using this variable.
 *
 * Time (N^2)
 * Space (1), or (N) if count return value
 * */
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for( int i = 0; i < s.size(); ++i ) {
            const int length1 = expandAroundCenter( s, i, i );
            const int length2 = expandAroundCenter( s, i, i + 1 );

            const int length = std::max( length1, length2 );
            if( length > maxLength ) {
                maxLength = length;
                start = i - ( length - 1 ) / 2;
            }
        }

        return s.substr( start, maxLength );
    }

    int expandAroundCenter( const std::string& s, int left, int right ) const {
        while( left >= 0 && right < s.size() && s[ left ] == s[ right ] ) {
            --left;
            ++right;
        }

        return right - left - 1;
    }
};
} // namespace V1
