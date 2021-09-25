/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/

#include <string>

using std::stirng;

namespace {
/*
N - length of s

Time O(N)
Space O(1)
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int right = 0;
        
        for( char ch : s ) {
            if( ch == '(' ) {
                ++left;
            }
            else {
                if( left == 0 )
                    ++right;
                else
                    --left;
            }
        }
        
        return left + right;
    }
};
} // namespace
