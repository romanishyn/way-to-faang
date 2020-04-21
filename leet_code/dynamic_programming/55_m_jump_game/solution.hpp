/*
https://leetcode.com/problems/jump-game/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <string.h>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
//    bool canJump(vector<int>& nums) {
//        vector< bool > dp( nums.size() );
//
//        dp[ 0 ] = true;
//        for( int i = 1; i < nums.size(); ++i ) {
//            for( int j = 0; j < i; ++j ) {
//                if( dp[ j ] && ( i - j <= nums[ j ] ) ) {
//                    dp[ i ] = true;
//                    continue;
//                }
//            }
//        }
//
//        return dp.back();
//    }

    bool canJump(vector<int>& nums) {
        int maxJump = nums[ 0 ];

        for( int i = 1; i < nums.size() - 1; ++i ) {
            if( i <= maxJump ) {
                maxJump = std::max( maxJump, i + nums[ i ] );
            }
        }

        return maxJump >= nums.size() - 1;
    }
};

