/*
https://leetcode.com/problems/group-anagrams/
*/

#pragma once

#include <string>
#include <stack>

using std::string;

namespace V1 {
/*
 * Last closing parenthesis should correspond to first opening parenthesis. To deal with this idea we need a stack.
 * We go through entire string and see on each character if it's a opening parenthesis then push it onto the stack. Otherwise we
 * encounter a closing parenthesis. We check if stack is empty, that mean unmatched closing character (current char),
 * then this implies an invalid expression. And we take top element from stack and compare it on matching with
 * current character. In the end, if we have not empty stack, that implies we have unmatched characters,
 * this is case unmatched left.
 *
 * n: # of characters in string
 *
 * Time: O(n)
 * Space: O(n)
 * */
class Solution {
public:
    bool isValid(string s) {
        std::stack< char > stack;

        for( char c : s ) {
            if( c == '(' || c == '{' || c == '[' ) // Push left brackets
                stack.push( c );
            else {
                if( stack.empty() ) // Unmatched right char
                    return false;

                const char leftBracket = stack.top();
                stack.pop();

                if( ( leftBracket == '(' && c != ')' ) || // Ensure match (if right bracket)
                    ( leftBracket == '{' && c != '}' ) ||
                    ( leftBracket == '[' && c != ']' ) )
                    return false;
            }
        }

        return stack.empty(); // In case unmatched left
    }
};
} // namespace V1
