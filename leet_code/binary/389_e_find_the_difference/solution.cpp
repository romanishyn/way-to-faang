/*
https://leetcode.com/problems/find-the-difference/
*/

#include <array>
#include <string>

using std::string;

namespace {
/*
Hash array

N - size of string

Time O(N)
Space O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        std::array< char, 26 > letters{};

        ++letters[ t.back() - 'a' ];
        for( int i = 0; i < s.size(); ++i ) {
            --letters[ s[ i ] - 'a' ];
            ++letters[ t[ i ] - 'a' ];
        }

        for( int i = 0; i < letters.size(); ++i ) {
            if( letters[ i ] == 1 )
                return static_cast< char >( i + 'a' );
        }

        return 'a';
    }
};
} // namespace

namespace {
/*
Bit Manipulation

N - size of string

Time O(N)
Space O(1)
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = t.back();

        for( int i = 0; i < s.size(); ++i ) {
            ans ^= s[ i ];
            ans ^= t[ i ];
        }

        return ans;
    }
};
} // namespace
