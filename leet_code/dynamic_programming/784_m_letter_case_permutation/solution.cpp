/*
https://leetcode.com/problems/letter-case-permutation/
*/

#include <vector>
#include <cctype>

using std::vector;

namespace V1 {
/*
Using Knapsack Problem approack

N - legth of S

Time O(N*2^N), 2^(N+1) operations, N - to copy string
Space O(N*2^N)
*/
class Solution {

    using Strings = std::vector< std::string >;

public:
    vector<string> letterCasePermutation(string S) {
        Strings result;
        permute( result, S, 0 );
        return result;
    }

private:
    void permute( Strings& result, std::string str, int idx ) {
        if( str.size() == idx ) {
            result.push_back( std::move( str ) );
            return;
        }

        permute( result, str, idx + 1 );

        if( std::isalpha( str[ idx ] ) ) {
            str[ idx ] = changeCase( str[ idx ] );
            permute( result, std::move( str ), idx + 1 );
        }
    }

    char changeCase( unsigned char c ) {
        return std::islower( c ) ? std::toupper( c ) : std::tolower( c );
    }
};
} // namespace V1

namespace V2 {
/*
Backtracking approach

N - length of S

Time O(N*2^N)
Space O(N*2^N)
*/
class Solution {

    using Strings = std::vector< std::string >;

public:
    vector<string> letterCasePermutation(string S) {
        Strings result;
        permute( result, S, 0 );
        return result;
    }

private:
    void permute( Strings& result, std::string& str, int idx ) {
        result.push_back( str );

        for( int i = idx; i < str.size(); ++i ) {
            if( !std::isalpha( str[ i ] ) )
                continue;

            char temp = str[ i ];
            str[ i ] = changeChar( str[ i ] );
            permute( result, str, i + 1 );
            str[ i ] = temp;
        }
    }

    char changeChar( unsigned char c ) {
        return std::islower( c ) ? std::toupper( c ) : std::tolower( c );
    }
};
} // namespace V2

namespace V3 {
/*
Breadth First Search (cascading approach)

N - length of S

Time O(N*2^N)
Space O(N*2^N)
*/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result{ S };

        for( int pos = 0; pos < S.size(); ++pos ) {
            if( !std::isalpha( S[ pos ] ) )
                continue;

            const int levelSize = result.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto copy = result[ i ];
                copy[ pos ] = changeChar( copy[ pos ] );
                result.push_back( std::move( copy ) );
            }
        }

        return result;
    }
private:
    char changeChar( unsigned char c ) {
        return std::isupper( c ) ? std::tolower( c ) : std::toupper( c );
    }
};
} // namespace V3
