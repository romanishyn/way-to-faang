/*
https://leetcode.com/problems/different-ways-to-add-parentheses/
*/

#include <unordered_map>
#include <string>
#include <string_view>

namespace {
/*
Devide and Conqer + memoization

1. Iteratae through expresion character by character
2. we can break the expresion into two halfs whenever get an operators (+,-,*)
3. thw two parts can be calculated by recursively calling the function
4. Once we have the evalution result from the left and right halves, we can combine them to produce all results.

N - length of input

Time (N*2^N)
Space (2^N)

Actual complexites are: O(4^N/sqrt(N)), Catalan number https://en.wikipedia.org/wiki/Catalan_number
*/
class Solution {

    using Memo = std::unordered_map< std::string_view, std::vector< int > >;

public:
    vector<int> diffWaysToCompute(string input) {
        Memo memo;
        return diffWaysToCompute( input, memo );
    }

private:
    vector< int > diffWaysToCompute( std::string_view str, Memo& memo ) {
        if( auto it = memo.find( str ); it != memo.end() )
            return it->second;

        vector< int > result;

        for( int i = 0; i < str.size(); ++i ) {
            const char c = str[ i ];

            if( std::isdigit( c ) )
                continue;

            auto left = diffWaysToCompute( str.substr( 0, i ), memo );
            auto right = diffWaysToCompute( str.substr( i + 1 ), memo );

            for( int x : left ) {
                for( int y : right ) {
                    if( c == '+' )
                        result.push_back( x + y );
                    else if( c == '-' )
                        result.push_back( x - y );
                    else
                        result.push_back( x * y );
                }
            }
        }

        if( result.empty() ) {
            int number = 0;
            std::from_chars( str.begin(), str.begin() + str.size(), number );
            result.push_back( number );
        }

        return memo[ str ] = result;
    }
};
} // namespace