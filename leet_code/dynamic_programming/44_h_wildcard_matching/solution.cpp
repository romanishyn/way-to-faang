/*
 * https://leetcode.com/problems/wildcard-matching/
 * */

#include <string>
#include <string_view>
#include <vector>

using std::string;


namespace {
/*
S - s.size
P - p.size

Time O(S*P)
Space O(S*P)
*/
class Solution {
    enum class State{
        Unknown,
        True,
        False
    };
    using Memo = std::vector< std::vector< State > >;
    
public:
    bool isMatch(string s, string p) {
        Memo memo( s.size() + 1, std::vector< State >( p.size() + 1, State::Unknown ) );
        return isMatch( s, p, 0, 0, memo );
    }

private:
    bool isMatch( const std::string& s, const std::string& p, int sIdx, int pIdx, Memo& memo ) {
        if( memo[ sIdx ][ pIdx ] != State::Unknown )
            return memo[ sIdx ][ pIdx ] == State::True;
        
        bool result = false;
        
        if( p.size() == pIdx )
            result = s.size() == sIdx;
        else if( p[ pIdx ] == '*' ) {
            if( isMatch( s, p, sIdx, pIdx + 1, memo ) )
                result = true;
            else if(sIdx < s.size() && isMatch( s, p, sIdx + 1, pIdx, memo ) )
                result = true;
        }
        else {
            const bool firstMatch = sIdx >= s.size() ? false : s[ sIdx ] == p[ pIdx ] || p[ pIdx ] == '?';
            result = firstMatch && isMatch( s, p, sIdx + 1, pIdx + 1, memo );
        }
        
        memo[ sIdx ][ pIdx ] = result ? State::True : State::False;
        return result;
    }
};
} // namespace