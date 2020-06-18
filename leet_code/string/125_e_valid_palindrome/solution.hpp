/*
https://leetcode.com/problems/valid-palindrome/
*/

#pragma once

#include <string>
#include <stack>

using std::string;

namespace V1 {
/*
 * In this problem we'll use Two Pointers Technique. We need left and right pointer.
 * We gonna move left point to right side of string and for right pointer vise versa, until they meet or cross.
 * Need find valid position for left pointer, so we move forward pointer until it less than right and it isn't a alpha or digit.
 * For right the same actions, but need move to backward. And then we need again check if left less then right and compare
 * those characters, but beforehand we need to make them in the same case. If they are not equal return false.
 * At the end, return true.
 *
 * n: # of characters in string
 *
 * Time O(n)
 * Space O(1)
 * */
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while( left < right ) {
            while( left < right && !std::isalnum( s[ left ] ) )
                ++left;

            while( left < right && !std::isalnum( s[right ] ) )
                --right;

            if( left < right && std::tolower( s[ left ] ) != std::tolower( s[ right ]) )
                return false;

            ++left;
            --right;
        }

        return true;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while( left < right ) {
            if( !std::isalnum( s[ left ] ) )
                ++left;
            else if( !std::isalnum( s[ right ] ) )
                --right;
            else {
                if( std::tolower( s[ left ] ) != std::tolower( s[ right ] ) )
                    return false;

                ++left;
                --right;
            }
        }

        return true;
    }
};
} // namespace V2
