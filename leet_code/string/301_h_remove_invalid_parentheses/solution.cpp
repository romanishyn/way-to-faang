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


namespace {
/*
N - size of s

Time O((2^N)*N)
Space O(N), do not count result
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        std::unordered_set< std::string > result;
        std::string path;
        const int targetLength = s.size() - countInvalidParentheses( s );
        removeInvalidParentheses( s, 0, targetLength, result, path );
        return { begin( result ), end( result ) };
    }

private:
    int countInvalidParentheses( const std::string& str ) {
        int left = 0;
        int right = 0;
        for( char ch : str ) {
            if( ch == '(' )
                ++left;
            else if( ch == ')') {
                if( left > 0 )
                    --left;
                else
                    ++right;
            }
        }
        return left + right;
    }

    void removeInvalidParentheses( const std::string& s, int idx, int targetLength,
                                   std::unordered_set< std::string >& result, std::string& path ) {
        if( path.size() == targetLength ) {
            if( countInvalidParentheses( path ) == 0 )
                result.insert( path );

            return;
        }
        if( s.size() == idx )
            return;

        if( targetLength - path.size() > s.size() - ( idx ) )
            return;

        if( ! std::isalpha( s[ idx ] ) )
            removeInvalidParentheses( s, idx + 1, targetLength, result, path );

        path.push_back( s[ idx ] );
        removeInvalidParentheses( s, idx + 1, targetLength, result, path );
        path.pop_back();
    }
};
} // namespace

namespace {
/*
N - size of s

Time O((2^N)*N)
Space O(N), do not count result
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        if( s.size() < 1 )
            return { s };

        std::queue< std::string > todo;
        std::unordered_set< std::string > seen;

        todo.push( s );
        seen.insert( s );

        std::vector< std::string > result;

        while( result.empty() && ! todo.empty() ) {
            const int levelSize = todo.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto str = todo.front();
                todo.pop();
                
                if( isValidParentheses( str ) ) {
                    result.push_back( str );
                }

                if( ! result.empty() )
                    continue;

                for( int idx = 0; idx < str.size(); ++idx ) {
                    if( std::isalpha( str[ idx ] ) )
                        continue;

                    auto child = str.substr( 0, idx ) + str.substr( idx + 1 );
                    if( seen.insert( child ).second )
                        todo.push( std::move( child ) );
                }
            }
        }
        return result;
    }

private:
    bool isValidParentheses( const std::string & str ) {
        int left = 0;
        int right = 0;
        for( char ch : str ) {
            if( ch == '(')
                ++left;
            else if( ch == ')' ) {
                if( left  > 0 )
                    --left;
                else
                    ++right;
            }
        }
        
        return left + right == 0;
    }
};
} // namespace
