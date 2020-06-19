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
 * i
 * i + 1
 *
 * Time (n^2)
 * Space (1)
 * */
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if( s.size() < 2 )
            return s;

        for( int i = 0; i < s.size() - 1; ++i ) {
            expandFromMiddle( s, i, i );
            expandFromMiddle( s, i, i + 1 );
        }

        return s.substr( m_start, m_start + m_length );
    }

private:
    void expandFromMiddle( const std::string & s, int left, int right ) {
        while( left >= 0 && right < s.size() && s[ left ] == s[ right ] ) {
            --left;
            ++right;
        }

        if( m_length < right - left - 1 ) {
            m_start = left + 1;
            m_length = right - left - 1;
        }
    }

private:
    int m_start = 0;
    int m_length = 0;
};
} // namespace V1
public class Solution {
private int lo, maxLen;

public String longestPalindrome(String s) {
        int len = s.length();
        if (len < 2)
            return s;

        for (int i = 0; i < len-1; i++) {
            extendPalindrome(s, i, i);  //assume odd length, try to extend Palindrome as possible
            extendPalindrome(s, i, i+1); //assume even length.
        }
        return s.substring(lo, lo + maxLen);
    }

private void extendPalindrome(String s, int j, int k) {
        while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
            j--;
            k++;
        }
        if (maxLen < k - j - 1) {
            lo = j + 1;
            maxLen = k - j - 1;
        }
    }}