/*
https://leetcode.com/problems/multiply-strings/
*/

#include <string>

using std::string;

namespace {
/*
N - size of num1
M - size of num2

Time O(N*M)
Space O(N+M)
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        const int size1 = num1.size();
        const int size2 = num2.size();

        std::vector< int > result( size1 + size2 );

        for( int i = size1 - 1; i >= 0; --i ) {
            const int digit1 = num1[ i ] - '0';
            for( int j = size2 - 1; j >= 0; --j ) {
                const int digit2 = num2[ j ] - '0';

                int tempNum = digit1 * digit2 + result[ i + j + 1 ];
                result[ i + j + 1 ] = tempNum % 10;
                result[ i + j ] += tempNum / 10;
            }
        }

        int idx = 0;
        for( int mostSignificantDigit : result ) {
            if( mostSignificantDigit != 0 )
                break;

            ++idx;
        }

        std::string number;
        for( int i = idx; i < result.size(); ++i ) {
            number += static_cast< char >( result[ i ] + '0' );
        }

        return number.empty() ? "0" : number;
    }
};
} //
