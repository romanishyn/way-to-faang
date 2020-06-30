/*
https://leetcode.com/problems/palindromic-substrings/
*/

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

// TODO: impl DP approach https://leetcode.com/problems/palindromic-substrings/discuss/144443/Bottom-up-DP

namespace V1 {
/*
 * Idea is start from each center for odd and even length and expand around this center.
 *
 * Time (N^2), each expansion might do O(N) work
 * Space (1)
 * */
class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;

        for( int i = 0; i < s.size(); ++i ) {
            result += countSubstrings( s, i, i );
            result += countSubstrings( s, i, i + 1 );
        }

        return result;
    }

private:
    int countSubstrings( const std::string & s, int left, int right ) const {
        int result = 0;

        while( left >= 0 && right < s.size() && s[ left ] == s[ right ] ) {
            ++result;
            --left;
            ++right;
        }

        return result;
    }
};
} // namespace V1
