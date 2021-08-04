/*
https://leetcode.com/problems/add-binary/
*/

#include <string>

namespace {
/*
N - a.size
M - b.size
T = max(N,M)

Time O(T)
Space O(T)
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        std::string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while( i >= 0 || j >= 0 || carry > 0 ) {
            int sum = carry;
            if( i >= 0 ) {
                sum += ( a[ i ] - '0' );
                --i;
            }
            if( j >= 0 ) {
                sum += ( b[ j ] - '0' );
                --j;
            }
            carry = sum / 2;
            sum %= 2;
            result.push_back( static_cast< char >( sum + '0' ) );
        }
        std::reverse( begin( result ), end( result ) );
        return result;
    }
};
} // namespace