/*
https://leetcode.com/problems/expression-add-operators/solution/
*/

namespace {
/*
12345
1+2*3
0 000

N - size of num

Time O((4^N)*N)
Space O(N)
*/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        std::vector< std::string > result;
        std::vector< std::string > tokens;

        addOperators( num, 0, target, 0, 0, 0, tokens, result );

        return result;
    }

private:
    void addOperators(const std::string& num, int idx, int target, long value, long prev, long curr
                    , std::vector< std::string >& tokens, std::vector< std::string >& result )
    {
        if( idx == num.size() ) {
            if( value == target && curr == 0 ) {
                std::string str;
                for( int i = 1; i < tokens.size(); ++i )
                    str += tokens[ i ];

                result.push_back( std::move( str ) );
            }
            return;
        }

        curr = curr * 10 + ( num[ idx ] - '0' );

        if( curr > 0 ) {
            // no operation
            addOperators( num, idx + 1, target, value, prev, curr, tokens, result );
        }

        // addition
        tokens.push_back( "+" );
        tokens.push_back( std::to_string( curr ) );
        addOperators( num, idx + 1, target, value + curr, curr, 0, tokens, result );
        tokens.pop_back();
        tokens.pop_back();

        if( tokens.size() > 0 ) {
            // substruction
            tokens.push_back( "-" );
            tokens.push_back( std::to_string( curr ) );
            addOperators( num, idx + 1, target, value - curr, -curr, 0, tokens, result );
            tokens.pop_back();
            tokens.pop_back();

            // multiplication
            tokens.push_back( "*" );
            tokens.push_back( std::to_string( curr ) );
            addOperators( num, idx + 1, target, value - prev + ( prev * curr ), prev * curr, 0, tokens, result );
            tokens.pop_back();
            tokens.pop_back();
        }
    }
};
} // namespace