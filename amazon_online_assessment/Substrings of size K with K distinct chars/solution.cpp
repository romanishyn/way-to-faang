/*
https://leetcode.com/discuss/interview-question/370112/
*/

#include <string>
#include <unordered_set>
#include <vector>
#include <array>

namespace {
class Solution {
public:
    std::vector< std::string > uniqueSubstringSizeK( const std::string& str, int k ) {
        std::array< int, 26 > chars{};
        int count = 0;

        std::unordered_set< std::string > substrings;
        for( int left = 0, right = 0; right < str.size(); ++right ) {
            const int rightChar = str[ right ] - 'a';
            ++chars[ rightChar ];
            if( chars[ rightChar ] == 1 )
                ++count;

            if( right - left + 1 == k ) {
                if( count == k )
                    substrings.insert( str.substr( left, k ) );

                const int leftChar = str[ left ] - 'a';
                --chars[ leftChar ];
                if( chars[ leftChar ] == 0 )
                    --count;

                ++left;
            }
        }

        return { begin( substrings ), end( substrings ) };
    }
}; // class Solution

int main() {
    Solution solution;
    std::string str = "abcabc";

    auto print = [ &solution ]( const std::string& str, int k ) mutable {
        for( auto str : solution.uniqueSubstringSizeK( str, k ) )
            std::cout << str << " ";
        std::cout << std::endl;
    };

    print( "abcabc", 3 );
    print( "abacab", 3 );
    print( "awaglknagawunagwkwagl", 4 );
    
    std::set< std::string > expected{ "wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag" };
    auto res = solution.uniqueSubstringSizeK( "awaglknagawunagwkwagl", 4 );
    std::set< std::string > result( begin( res ), end( res ) );
    assert( expected == result ); 

    return 0;
}
} // namespace
