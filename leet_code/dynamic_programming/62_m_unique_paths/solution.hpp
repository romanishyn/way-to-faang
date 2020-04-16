/*
https://leetcode.com/problems/unique-paths/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <string.h>
#include <algorithm>

using std::string;
using std::vector;

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        m_m = m - 1;
//        m_n = n - 1;
//
//        return impl( 0, 0 );
//    }
//
//private:
//    int m_m = 0;
//    int m_n = 0;
//
//    int impl( int i, int j ) {
//        if( i == m_m && j == m_n )
//            return 1;
//
//        int result = 0;
//
//        if( i < m_m )
//            result += impl( i + 1, j );
//
//        if( j < m_n )
//            result += impl( i, j + 1 );
//
//        return result;
//    }
//};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector< int > > t( m, vector<int>( n, 1 ) );

        for( int i = 1; i < m; ++i ) {
            for( int j = 1; j < n; ++j ) {
                t[ i ][ j ] = t[ i - 1 ][ j ] + t[ i ][ j - 1 ];
            }
        }

        return t.back().back();
    }
};

