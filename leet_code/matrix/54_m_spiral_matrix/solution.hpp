/*
https://leetcode.com/problems/spiral-matrix/
*/

#pragma once

#include <vector>
#include <algorithm>


using std::vector;

namespace V1 {
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if( matrix.empty() )
            return result;

        int c1 = 0;
        int c2 = matrix[ 0 ].size() - 1;
        int r1 = 0;
        int r2 = matrix.size() - 1;

        while( c1 <= c2 && r1 <= r2 ) {
            for( int c = c1; c <= c2; ++c )
                result.push_back( matrix[ r1 ][ c ] );

            for( int r = r1 + 1; r <= r2; ++r )
                result.push_back( matrix[ r ][ c2 ] );

            if( c1 < c2 && r1 < r2 ) {
                for( int c = c2 - 1; c >= c1 + 1; --c )
                    result.push_back( matrix[ r2 ][ c ] );

                for( int r = r2; r >= r1 + 1; --r )
                    result.push_back( matrix[ r ][ c1 ] );
            }

            ++c1;
            --c2;
            ++r1;
            --r2;
        }

        return result;
    }
};
} // namespace V1

