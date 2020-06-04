/*
https://leetcode.com/problems/merge-intervals/
*/

#pragma once

#include <vector>
#include <algorithm>

using std::vector;

/*
 * First we sort intervals in ascending order, namely we can sort intervals by their 'start' value.
 * It create contiguous blocks of intervals that we can merge.
 * Then we insert first interval in our "result" vector, and continue considering each interval in turn as follows:
 * if current interval begins after previous interval ends, then they do not overlap each other and we can append
 * current interval to result vector. Otherwise, they do overlap, and we need merge them by updating the end of
 * the end previous interval, if it's less end of current interval.
 * */

namespace V1 {
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if( intervals.size() < 2 )
            return intervals;

        // NOTE: my bug was : lhs[ 1 ] < rhs[ 0 ]
        auto comparator = []( const auto& lhs, const auto& rhs ) {
            return lhs[ 0 ] < rhs[ 0 ];
        };

        std::sort( intervals.begin(), intervals.end(), comparator );

        vector< vector< int > > result;
        result.push_back( intervals[ 0 ] );

        for( int i = 1; i < intervals.size(); ++i ) {
            auto & back = result.back();
            if( back[ 1 ] >= intervals[ i ][ 0 ] ) {
                back[ 0 ] = std::min( back[ 0 ], intervals[ i ][ 0 ] );
                back[ 1 ] = std::max( back[ 1 ], intervals[ i ][ 1 ] );
            }
            else {
                result.push_back( intervals[ i ] );
            }
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto comparator = []( const auto& lhs, const auto& rhs ) {
            return lhs[ 0 ] < rhs[ 0 ];
        };

        std::sort( intervals.begin(), intervals.end(), comparator );

        vector<vector<int>> result;

        for( const auto& interval : intervals ) {
            if( result.empty() || result.back()[ 1 ] < interval[ 0 ] ) {
                result.push_back( interval );
            }
            else {
                result.back()[ 1 ] = std::max( result.back()[ 1 ], interval[ 1 ] );
            }
        }

        return result;
    }
};
}