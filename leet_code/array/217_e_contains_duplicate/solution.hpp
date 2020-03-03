//https://leetcode.com/problems/two-sum/

#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;

class Solution {
public:
//    bool containsDuplicate(vector<int>& nums) {
//        std:unordered_set<int> set;
//        for( int x : nums ) {
//            if( !set.insert( x ).second ) {
//                return true;
//            }
//        }
//
//        return false;
//    }


    bool containsDuplicate(vector<int>& nums) {
        std::sort( nums.begin(), nums.end() );
        const int size = nums.size();
        for(int i = 1; i < size; ++i ) {
            if( nums[ i ] == nums[ i - 1 ] )
                return true;
        }

        return false;
    }
};
