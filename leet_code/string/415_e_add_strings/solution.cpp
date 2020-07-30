/*
 * https://leetcode.com/problems/add-strings/
 * */

#include <string>

using std::string;

namespace V1 {
/*
 * N1 - length of num1
 * N2 - length of num2
*
 * Time O(max(N1, N2)), we do max(N1, N2) iterations at most
 * Space O(max(N1, N2)), because length of new string is at most max(N1, N2) + 1
 * */
class Solution {
public:
    string addStrings(string num1, string num2) {
        std::string result;

        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        int carry = 0;

        while( idx1 >= 0 || idx2 >= 0 || carry > 0 ) {
            int x = idx1 < 0 ? 0 : num1[ idx1 ] - '0';
            int y = idx2 < 0 ? 0 : num2[ idx2 ] - '0';

            int value = ( x + y + carry ) % 10;
            carry = ( x + y + carry ) / 10;

            result.push_back( value + '0' );

            --idx1;
            --idx2;
        }

        reverse( result );
        return result;
    }

private:
    void reverse( std::string& str ) {
        int left = 0;
        int right = str.size() - 1;
        while( left < right ) {
            std::swap( str[ left++ ], str[ right-- ] );
        }
    }
};
} // namespace V1
