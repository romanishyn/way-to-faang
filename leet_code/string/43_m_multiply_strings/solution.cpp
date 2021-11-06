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
} // namespace

namespace {
/*
M - num1.size
N - num2.size

Time O(M*N)
Space O(1)
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1 == "0" || num2 == "0" )
            return "0";

        reverse( begin( num1 ), end( num1 ) );
        reverse( begin( num2 ), end( num2 ) );

        string result( num1.size() + num2.size(), '0' );

        for( int i = 0; i < num1.size(); ++i ) {
            const int digit1 = num1[ i ] - '0';
            for( int j = 0; j < num2.size(); ++j ) {
                const int digit2 = num2[ j ] - '0';

                const int num = digit1 * digit2 + result[ i + j ] - '0';
                result[ i + j ] = num % 10 + '0';
                result[ i + j + 1 ] += num / 10;
            }
        }

        if( result.back() == '0' )
            result.pop_back();

        reverse( begin( result ), end( result ) );

        return result;
    }
};
} // namespace
