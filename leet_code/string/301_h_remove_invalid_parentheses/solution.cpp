/*
https://leetcode.com/problems/remove-invalid-parentheses/
*/

#include <vector>
#include <string>
#include <string_view>

using std::vector;
using std::string;

namespace {
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        const int invalidParentheses = coundInvalidParentheses( s );
        if( invalidParentheses == 0 ) {
            return { s };
        }

        unordered_set< string > validStrings;
        string path;
        const int pathSize = s.size() - invalidParentheses;

        fillValidStrings( validStrings, s, 0 /*idx*/, path, pathSize );
        return { validStrings.begin(), validStrings.end() };
    }

private:
    void fillValidStrings( unordered_set< string >& validStrings, const std::string& data, int idx, std::string& path, int maxPathSize ) {
        if( path.size() == maxPathSize ) {
            if( coundInvalidParentheses( path ) == 0 )
                validStrings.insert( path );

            return;
        }

        const int iterations = data.size() - ( maxPathSize - path.size() - 1 );
        if( idx >= iterations )
            return;

        if( data[ idx ] != '(' && data[ idx ] != ')' ) {
            path.push_back( data[ idx ] );
            fillValidStrings( validStrings, data, idx + 1, path, maxPathSize );
            path.pop_back();
        }
        else {
            fillValidStrings( validStrings, data, idx + 1, path, maxPathSize );

            path.push_back( data[ idx ] );
            fillValidStrings( validStrings, data, idx + 1, path, maxPathSize );
            path.pop_back();
        }
    }

    int coundInvalidParentheses( std::string_view str ) {
        int left = 0;
        int right = 0;

        for( char c : str ) {
            if( c == '(' ) {
                ++left;
            }
            else if( c == ')' ) {
                if( left == 0 )
                    ++right;
                else
                    --left;
            }
        }

        return left + right;
    }
};
} // namespace

namespace {
/*
N - size of s

Time O(N*2^N)
Space O(N*2^N)
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if( s.size() <= 1 )
            return { s };

        std::queue< std::string > todo;
        std::unordered_set< std::string > seen;

        todo.push( s );
        seen.insert( s );

        std::vector< std::string > result;

        while( result.empty() && ! todo.empty() ) {
            const int levelSize = todo.size();

            for( int i = 0; i < levelSize; ++i ) {
                std::string str = todo.front();
                todo.pop();

                if( isValid( str ) ) {
                    result.push_back( str );
                    continue;
                }

                for( int i = 0; i < str.size(); ++i ) {
                    if( str[ i ] != '(' || str[ i ] != ')' )
                        continue;

                    std::string newStr = str.substr( 0, i ) + str.substr( i + 1 );
                    if( seen.insert( newStr ).second ) {
                        todo.push( newStr );
                    }
                }
            }
        }

        return result;
    }

private:
    bool isValid( const std::string& str ) {
        int left = 0;
        int right = 0;
        for( char c : str ) {
            if( c == '(' ) {
                ++left;
            }
            else if( c == ')' ) {
                if( left == 0 )
                    ++right;
                else
                    --left;
            }
        }

        return left + right == 0;
    }
};
} // namespace
