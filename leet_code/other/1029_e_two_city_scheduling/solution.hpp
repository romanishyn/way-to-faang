/*
https://leetcode.com/problems/two-city-scheduling/
*/

#pragma once

#include <vector>
#include <algorithm>


using std::vector;

namespace V1 {
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        std::sort( costs.begin(), costs.end(),
            []( const auto& lhs, const auto rhs )
            {
                return std::abs( lhs[ 0 ] - lhs[ 1 ] ) > std::abs( rhs[ 0 ] - rhs[ 1 ] );
            }
        );

        int result = 0;
        int countA = 0;
        int countB = 0;
        const int n = costs.size() / 2;

        for( const auto& cost: costs ) {
            if( countA < n && countB < n ) {
                if( cost[ 0 ] < cost[ 1 ] ) {
                    ++countA;
                    result += cost[ 0 ];
                }
                else {
                    ++countB;
                    result += cost[ 1 ];
                }
            }
            else if( countA < n ) {
                ++countA;
                result += cost[ 0 ];
            }
            else {
                ++countB;
                result += cost[ 1 ];
            }
        }

        return result;
    }
};
} // namespace V1

