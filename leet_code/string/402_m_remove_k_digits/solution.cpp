/*
https://leetcode.com/problems/remove-k-digits/
*/

#include <string>

using std::string;

namespace {
/*
N - size of num
K - k

Time O(N*K)
Space O(1)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        for( int i = 0; i < k; ++i ) {
            num = removeOneDigit( num );
        }

        return num;
    }

private:
    std::string removeOneDigit( string num ) {
        if( num.size() <= 1 )
            return "0";

        bool removed = false;
        for( int i = 1; i < num.size(); ++i ) {
            if( num[ i - 1 ] > num[ i ] ) {
                num = num.substr( 0, i - 1 ) + num.substr( i );
                removed = true;
                break;
            }
        }

        if( ! removed )
            num.pop_back();

        int pos = num.find_first_not_of( '0' );
        if( pos == std::string::npos )
            return "0";
        else
            return num.substr( pos );
    }
};
} //namespace

namespace {
/*
Dready approach

N - size of num

Time O(N)
Space O(N)
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        std::deque< char > digits;
        for( int digit : num ) {
            while( ! digits.empty() && k > 0 && digits.back() > digit ) {
                digits.pop_back();
                --k;
            }
            digits.push_back( digit );
        }

        for( ; k > 0; --k ) {
            digits.pop_back();
        }

        auto it = std::find_if_not( begin( digits ), end( digits ), []( char ch ) { return ch == '0'; } );
        std::string result( it, end( digits ) );

        return result.empty() ? "0" : result;
    }
};
} // namespace


