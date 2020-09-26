/*
https://leetcode.com/problems/valid-palindrome-ii/
*/

#include <string>

using std::string;

namespace {
/*
N - length of string

Time O(N)
Space O(1)
*/
class Solution {
public:
    bool validPalindrome(string s) {
        if( s.size() <= 2 )
            return true;

        int left = 0;
        int right = s.size() - 1;
        while( left < right ) {
            if( s[ left ] != s[ right ] )
                return isPalindrome( s, left, right - 1 ) || isPalindrome( s, left + 1, right );

            ++left;
            --right;
        }

        return true;
    }

private:
    bool isPalindrome( const std::string& str, int left, int right ) {
        while( left < right ) {
            if( str[ left ] != str[ right ] )
                return false;

            ++left;
            --right;
        }

        return true;
    }
};
} // namespace

namespace {
/*
Solution to delete at most K

N - length of string
K - number of characters to delete

Time O(2^(N))
Space O(N)
*/
class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome( s, 0, s.size() - 1, 1 );
    }

private:
    bool isPalindrome( std::string_view str, int left, int right, int attemps ) {
        if( left >= right )
            return true;

        if( str[ left ] == str[ right ] )
            return isPalindrome( str, left + 1, right - 1, attemps );
        else {
            return attemps > 0
                && ( isPalindrome( str, left + 1, right, attemps - 1 ) || isPalindrome( str, left, right - 1, attemps - 1 ) );
        }
    }
};
} // namespace