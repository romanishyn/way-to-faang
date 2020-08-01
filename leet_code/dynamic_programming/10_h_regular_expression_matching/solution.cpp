/*
 * https://leetcode.com/problems/regular-expression-matching/
 * */

#include <string>
#include <string_view>
#include <vector>

using std::string;

namespace V1 {
/*
 * Recursive approach
 * To understand the code, need think about it, how it should work, if you try determine answer on your own
 *
 * First of all, define base case:
 * 1) if pattern is empty, no need to continue. Return true if text is empty as well, otherwise false
 * Second step is define if first characters matched, sure, if s is empty then false, else if first chars are equal or
 * pattern[ 0 ] == '.', then true, otherwise false.
 *
 * If second char of p is *, then check recursively two possible situations:
 * 1) get rid of prefix "$*" in p
 * 2) if firstCharMatched then , extract first char from s
 * Else call function recursively if firstCharMatched and then discard one char in each string
 *
 * Time () ??
 * Space () ??
 * */
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchImpl( s, p );
    }

private:
    bool isMatchImpl( std::string_view text, std::string_view pattern ) {
        if( pattern.empty() )
            return text.empty();

        const bool firstMatched = text.empty() ? false : text.front() == pattern.front() || pattern.front() == '.';

        if( pattern.size() >= 2 && pattern[ 1 ] == '*' ) {
            return isMatchImpl( text, pattern.substr( 2 ) )
                || ( firstMatched && isMatchImpl( text.substr( 1 ), pattern ) );
        }
        else {
            return firstMatched && isMatchImpl( text.substr( 1 ), pattern.substr( 1 ) );
        }
    }
};
} // namespace V1

namespace V2 {
/*
 * DP Top-Down
 * Almost the same solution as above
 *
 * Time O(T*P)
 * Space (T*P)
 * */
class Solution {

    enum class State { Unknown, Match, Unmatch };

    using Memo = std::vector< std::vector< State > >;

public:
    bool isMatch(string s, string p) {
        Memo memo( s.size() + 1, std::vector< State >( p.size() + 1, State::Unknown ) );
        return isMatch( s, p, 0, 0, memo );
    }

private:
    bool isMatch( const std::string& text, const std::string& pattern, int idxT, int idxP, Memo& memo ) {
        if( memo[ idxT ][ idxP ] != State::Unknown )
            return memo[ idxT ][ idxP ] == State::Match;

        bool result = false;

        if( idxP == pattern.size() ) {
            result = idxT == text.size();
        }
        else {
            const bool firstMatch = idxT >= text.size() ? false : text[ idxT ] == pattern[ idxP ] || pattern[ idxP ] == '.';

            if( idxP + 1 < pattern.size() && pattern[ idxP + 1 ] == '*' ) {
                result = isMatch( text, pattern, idxT, idxP + 2, memo )
                    ||   ( firstMatch && isMatch( text, pattern, idxT + 1, idxP, memo ) );
            }
            else {
                result = firstMatch && isMatch( text, pattern, idxT + 1, idxP + 1, memo );
            }
        }

        memo[ idxT ][ idxP ] = result ? State::Match : State::Unmatch;
        return result;
    }
};
} // namespace V2

namespace V3 {
// TODO: DP bottom-up
} // namespace V3
