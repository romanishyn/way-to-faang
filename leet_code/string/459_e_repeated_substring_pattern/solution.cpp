/*
https://leetcode.com/problems/repeated-substring-pattern/
*/

namespace {
/*
N - size of S

Time O(N^2)
Space O(N)
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int size = s.size();
        for( int i = 1; i <= size / 2; ++i ) {
            std::string substr = s.substr( 0, i );
            const int substrTimes = size / i;

            std::string newString;
            for( int j = 0; j < substrTimes; ++j ) {
                newString += substr;
            }

            if( s == newString ) {
                return true;
            }
        }
        return false;
    }
};
} // namespace
