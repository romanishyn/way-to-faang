/*
https://leetcode.com/problems/decode-string/
*/

#include <string>

using std::string;

namespace {
/*
Using recursive stack

Time - ?
Space - ?
*/
class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return decodeString( s, idx );
    }

private:
    std::string decodeString( const std::string& str, int& idx ) {
        std::string result;
        int number = 0;

        for( ; idx < str.size(); ++idx ) {
            const char ch = str[ idx ];
            if( std::isdigit( ch ) ) {
                number *= 10;
                number += static_cast< int >( ch - '0' );
            }
            else if( ch == '[' ) {
                auto subStr = decodeString( str, ++idx );
                for( int i = 0; i < number; ++i )
                    result += subStr;

                number = 0;
            }
            else if( ch == ']' ) {
                break;
            }
            else {
                result += ch;
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
Using stack

Time - ?
Space - ?
*/
class Solution {
public:
    string decodeString(string s) {
        int number = 0;
        std::string currStr;
        std::stack< std::pair< int, std::string/*prefix*/ > > stack;

        for( char ch : s ) {
            if( std::isdigit( ch ) ) {
                number = number * 10 + ( ch - '0' );
            }
            else if( ch == '[' ) {
                stack.emplace( number, std::move( currStr ) );
                number = 0;
                currStr.clear();
            }
            else if( ch == ']' ) {
                auto [repCurrStr, prefix] = stack.top();
                stack.pop();
                for( int i = 0; i < repCurrStr; ++i ) {
                    prefix += currStr;
                }

                currStr = std::move( prefix );
            }
            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};
} // namespace
