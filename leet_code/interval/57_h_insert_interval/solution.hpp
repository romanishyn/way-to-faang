/*
https://leetcode.com/problems/insert-interval/
*/

#pragma once

#include <vector>
#include <algorithm>

using std::vector;

namespace V1 {
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        std::size_t idx = 0;

        // left part without intersection
        while( idx < intervals.size() && intervals[ idx ][ 1 ] < newInterval[ 0 ] ) {
            res.push_back( intervals[ idx ] );
            ++idx;
        }

        bool flag = true;
        // newInterval part, insert newInterval (with or without merge)
        while( idx < intervals.size() && intervals[ idx ][ 0 ] <= newInterval[ 1 ] ) {
            newInterval[ 0 ] = std::min( newInterval[ 0 ], intervals[ idx ][ 0 ] );
            newInterval[ 1 ] = std::max( newInterval[ 1 ], intervals[ idx ][ 1 ] );
            ++idx;
        }
        res.push_back( newInterval );

        // right part without intersection
        while( idx < intervals.size() ) {
            res.push_back( intervals[ idx ] );
            ++idx;
        }

        return res;
    }
};
} // namespace V1

// NOTE: не понял этого решения
namespace V2 {
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
            return {newInterval};

        auto compare = [] (const vector<int>&intv1, const vector<int>&intv2)
            { return intv1[1] < intv2[0]; };

        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);

        auto itr1 = range.first;
        auto itr2 = range.second;

        for( int x : *itr1 )
            std::cout << x << " ";
        std::cout << std::endl;

        for( int x : *itr2 )
            std::cout << x << " ";
        std::cout << std::endl;

        if (itr1 == itr2) {
            intervals.insert(itr1, newInterval);
        } else {
            itr2--;
            *(itr2->begin()+0) = std::min(newInterval[0], *(itr1->begin()+0));
            *(itr2->begin()+1) = std::max(newInterval[1], *(itr2->begin()+1));
            intervals.erase(itr1, itr2);
        }
        return intervals;
    }
};
}
