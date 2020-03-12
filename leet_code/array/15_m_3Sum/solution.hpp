//https://leetcode.com/problems/two-sum/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        const int size = nums.size();
//        for( int i = 0; i < size; ++i ) {
//            for( int j = i + 1; j < size; ++j ) {
//                if( (nums[i] + nums[j]) == target )
//                    return { i, j };
//            }
//        }
//
//        return {};
//    }


    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for( int i = 0; i < nums.size(); ++i ) {
            auto it = map.find( target - nums[i] );
            if( it != map.end() ) {
                return { it->second, i };
            } else {
                map[ nums[ i ] ] = i;
            }
        }

        return {};
    }
};
