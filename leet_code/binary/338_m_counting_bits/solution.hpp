//https://leetcode.com/problems/counting-bits/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
//    vector<int> countBits(int num) {
//        vector<int> result;
//
//        for( int i = 0; i < num; ++i ) {
//            int count = 0;
//            int temp = i;
//            while( temp ) {
//                ++count;
//                temp &= temp - 1;
//            }
//
//            result.push_back( count );
//        }
//
//        return result;
//    }

    vector<int> countBits(int num) {
        vector<int> result( num + 1, 0 );

        for( int i = 1; i <= num; ++i ) {
            result[ i ] = result[ i & ( i - 1 ) ] + 1;
        }

        return result;
    }
};
