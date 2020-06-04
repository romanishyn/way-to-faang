/*
https://leetcode.com/problems/non-overlapping-intervals/
*/

#pragma once

#include <vector>
#include "unordered_set"
#include <algorithm>

using std::vector;

// NOTE: wrong solution
namespace V1 {
class Solution {
public:
    using Graph = std::vector< std::unordered_set< int > >;
    using Interval = std::vector< int >;

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        Graph graph = createGraph( intervals );

        vector< std::pair< int, int > > degrees( graph.size() );
        for( int i = 0; i < graph.size(); ++i ) {
            degrees.emplace_back( graph[ i ].size(), i );
        }

        std::sort( degrees.begin(), degrees.end(),
            []( const auto& pair1, const auto& pair2 ) { return pair1.first > pair2.first; } );

        int result = 0;

        for( auto [degree, idx ]: degrees ) {
            auto & set = graph[ idx ];

            if( set.empty() )
                continue;

            for( int x : set )
                graph[ x ].erase( idx );

            set.clear();
            ++result;
        }

        return result;
    }

    Graph createGraph( const vector<vector<int>>& intervals ) {
        Graph graph( intervals.size() );

        for( int i = 0; i < intervals.size() - 1; ++i ) {
            for( int j = i + 1; j < intervals.size(); ++j ) {
                if( overlap( intervals[ i ], intervals[ j ] ) ) {
                    graph[ i ].insert( j );
                    graph[ j ].insert( i );
                }
            }
        }

        return graph;
    }

    bool overlap( const Interval& interval1, const Interval& interval2 ) {
        if( interval1[ 0 ] <= interval2[ 0 ] && interval1[ 1 ] > interval2[ 0 ] )
            return true;
        else if( interval2[ 0 ] <= interval1[ 0 ] && interval2[ 1 ] > interval1[ 0 ] )
            return true;
        else
            return false;
    }
};
} // namespace V1

namespace V2 {
/* Comments: https://leetcode.com/problems/non-overlapping-intervals/discuss/91721/Short-Ruby-and-Python
 * Which interval would be the best first (leftmost) interval to keep? One that ends first, as it leaves the most room for the rest. So take one with smallest end, remove all the bad ones overlapping it, and repeat (taking the one with smallest end of the remaining ones). For the overlap test, just keep track of the current end, initialized with negative infinity.
 *
 * The text "One that ends first, as it leaves the most room for the rest" essentially gives the most intuitive description of the algorithm. All these interval problems can be solved with this idea, i.e., try to arrange intervals so that (1) no overlapping between two neighboring intervals, (2) they are as close as possible. The specific operations in the code target towards to these two goals. Thanks,
 *
 * https://leetcode.com/problems/non-overlapping-intervals/discuss/192615/Java-beats-100-greedy(intuition)
 * The intution here comes into play when we choose which interval to delete. If 2 intervals are overlapping always delete the interval with bigger end value. That way we ensure the upcoming intervals have lesser chance of overlapping with previous intervals and thus can gurantee lesser deletions.
Sorting of intervals is needed prior to applying greedy solution
 * */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int size = intervals.size();

        if( size <= 1 )
            return 0;

        std::sort( intervals.begin(), intervals.end(), []( const auto& lhs, const auto& rhs ){ return lhs[ 1 ] < rhs[ 1 ]; } );

        int result = 0;
        int prevEnd = intervals[ 0 ][ 1 ];

        for( int i = 1; i < intervals.size(); ++i ) {
            if( prevEnd > intervals[ i ][ 0 ] )
                ++result; // remove current interval
            else
                prevEnd = intervals[ i ][ 1 ];
        }

        return result;
    }
};
}

