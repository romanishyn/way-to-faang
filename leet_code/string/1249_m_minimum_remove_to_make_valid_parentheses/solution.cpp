/*
 * https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * */

#include <string>
#include <stack>
#include <unordered_set>

using std::string;

namespace V1 {
/*
 * Collect all indices of characters that need to remove, using a stack to determine which parenthesis is invalid.
 * And then remove all char by pointed collected indices in linear time.
 *
 * N - length of s
 *
 * Time (N)
 * Space (N)
 * */
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack< int > openBrackets;
        std::unordered_set< int > removeChar;

        for( int i = 0; i < s.size(); ++i ) {
            const char c = s[ i ];
            if( c == '(' ) {
                openBrackets.push( i );
            }
            else if( c == ')' ) {
                if( openBrackets.empty() ) {
                    removeChar.insert( i );
                }
                else {
                    openBrackets.pop();
                }
            }
        }

        while( !openBrackets.empty() ) {
            removeChar.insert( openBrackets.top() );
            openBrackets.pop();
        }

        return removeChars( s, removeChar );
    }

private:
    string removeChars( std::string s, const std::unordered_set< int >& indices ) {
        int left = 0;
        for( int right = 0; right < s.size(); ++right ) {
            if( !indices.count( right ) ) {
                std::swap( s[ left ], s[ right ] );
                ++left;
            }
        }

        return s.substr( 0, left );
    }
};
} // namespace V1