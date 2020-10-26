/*
https://leetcode.com/problems/count-and-say/
*/

#include <string>

using std::string;

namespace {
/*
Time - ?
Space - ?
*/
class Solution {
public:
    string countAndSay(int n) {
        std::string str{ "1" };

        for( int i = 1; i < n; ++i ) {
            std::string temp;
            int count = 0;
            for( int j = 0; j < str.size(); ++j ) {
                ++count;
                if( j == str.size() - 1 || str[ j ] != str[ j + 1 ] ) {
                    temp += count + '0';
                    temp += str[ j ];
                    count = 0;
                }
            }

            str = std::move( temp );
        }

        return str;
    }
};
} // namespace
