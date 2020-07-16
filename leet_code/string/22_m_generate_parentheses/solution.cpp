/*
 * https://leetcode.com/problems/generate-parentheses/
 * */

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace V1 {
/*
 * We know that in each prefix of well-formed string, number of open brackets greater than or equal to number of close brackets.
 * Follow this rule, we add '(' and ')' on each iteration.
 * 'open' represents how many left parentheses remains; 'close' represents how many right parentheses remains.
 *  The remaining right parentheses should be larger than left ones.
 * Append the string and terminate recursive calls when both open and close are zero
 *
 * 1) create result collection: vector< string >
 * Start recursive traversal:
 * 2) if open == 0 and close == 0 -> push string, stop recursive
 * 3) if open > 0 call( open - 1, close, string + '(')
 * 4) if open < close call( open, close - 1, string + ')')
 *
 * Time (2^(2*N) * N) - it's not correct
 * Space () - ??? difficult define
 * */
class Solution {
public:
    using Strings = std::vector< std::string >;

    vector<string> generateParenthesis(int n) {
        Strings result;
        generateParenthesis( result, n, n, "" );
        return result;
    }

private:
    void generateParenthesis( Strings& result, int open, int close, std::string str ) {
        if( open == 0 && close == 0 ) {
            result.push_back( std::move( str ) );
            return;
        }

        if( open > 0 )
            generateParenthesis( result, open - 1, close, str + '(' );
        if( open < close )
            generateParenthesis( result, open, close - 1, str + ')' );
    }
};
} // namespace V1


namespace V2 {
/*
 * The same like above, only improved memory usage
 * */
class Solution {
public:
    using Strings = std::vector< std::string >;

    vector<string> generateParenthesis(int n) {
        Strings result;
        std::string str( n * 2, ' ' );
        generateParenthesis( result, n, n, str, 0 );
        return result;
    }

private:
    void generateParenthesis( Strings& result, int open, int close, std::string& str, int idx ) {
        if( open == 0 && close == 0 ) {
            result.push_back( str );
            return;
        }

        if( open > 0 ) {
            str[ idx ] = '(';
            generateParenthesis( result, open - 1, close, str, idx + 1 );
        }
        if( open < close ) {
            str[ idx ] = ')';
            generateParenthesis( result, open, close - 1, str, idx +1  );
        }
    }
};
} // namespace V2

