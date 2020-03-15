//https://leetcode.com/problems/container-with-most-water/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = std::numeric_limits< int >::min();

        while( left < right ) {
            const int width = right - left;
            int tempArea = maxArea;

            if( height[ left ] < height[ right ] ) {
                tempArea = width * height[ left ];
                ++left;
            } else {
                tempArea = width * height[ right ];
                --right;
            }

            maxArea = std::max( maxArea, tempArea );
        }

        return maxArea;
    }
};
