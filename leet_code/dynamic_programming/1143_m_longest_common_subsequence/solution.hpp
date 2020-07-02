/*
https://leetcode.com/problems/longest-common-subsequence/
*/

#pragma once

#include <vector>
#include <unordered_map>
#include <string_view>
#include <string>

using std::string;

namespace V1 {
/*
 * Recursive
 *
 * N - size of text1
 * M - size of text2
 *
 * Time (2^(N+M))
 * Space (N+M)
 * */
class Solution {
public:
    int longestCommonSubsequence( string text1, string text2 ) {
        return longestCommonSubsequenceImpl( text1, text2 );
    }

private:
    int longestCommonSubsequenceImpl( std::string_view text1, std::string_view text2 ) {
        if( text1.empty() || text2.empty() )
            return 0;

        if( text1.front() == text2.front() )
            return 1 + longestCommonSubsequenceImpl( text1.substr( 1, text1.size() ), text2.substr( 1, text2.size() ) );
        else
            return std::max(
                longestCommonSubsequenceImpl( text1, text2.substr( 1, text2.size() ) ),
                longestCommonSubsequenceImpl( text1.substr( 1, text1.size() ), text2 )
            );
    }
};
} // namespace V1

namespace V2 {
/*
 * Recursion + Memoization
 *
 * N - size of text1
 * M - size of text2
 *
 * Time (N*M)
 * Space (N*M)
 * */
class Solution {
public:
    using Memo = std::vector< std::vector< int > >;

    int longestCommonSubsequence( string text1, string text2 ) {
        Memo memo( text1.size(), std::vector< int >( text2.size(), -1 ) );
        return longestCommonSubsequenceImpl( text1, text2, 0, 0, memo );
    }

private:
    int longestCommonSubsequenceImpl( const std::string& text1, std::string& text2, int idx1, int idx2, Memo& memo ) {
        if( text1.size() == idx1 || text2.size() == idx2 )
            return 0;

        if( memo[ idx1 ][ idx2 ] != -1 )
            return memo[ idx1 ][ idx2 ];

        if( text1[ idx1 ] == text2[ idx2 ] )
            memo[ idx1 ][ idx2 ] = 1 + longestCommonSubsequenceImpl( text1, text2, idx1 + 1, idx2 + 1, memo );
        else
            memo[ idx1 ][ idx2 ] = std::max(
                longestCommonSubsequenceImpl( text1, text2, idx1 + 1, idx2, memo ),
                longestCommonSubsequenceImpl( text1, text2, idx1, idx2 + 1, memo )
            );

        return memo[ idx1 ][ idx2 ];
    }
};
} // namespace V2

namespace V3 {
/*
 * Dynamic Programing
 *
 * N - size of text1
 * M - size of text2
 *
 * Time (N*M)
 * Space (N*M)
 * */
class Solution {
public:
    int longestCommonSubsequence( string text1, string text2 ) {
        std::vector< std::vector< int > > dp( text1.size() + 1, std::vector< int >( text2.size() + 1 ) );

        for( int i = 1; i < dp.size(); ++i ) {
            for( int j = 1; j < dp.front().size(); ++j ) {
                if( text1[ i - 1 ] == text2[ j - 1 ] ) {
                    dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ];
                }
                else {
                    dp[ i ][ j ] = std::max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
                }
            }
        }

        return dp.back().back();
    }
};
} // namespace V3
