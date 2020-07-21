/*
 * https://leetcode.com/problems/meeting-rooms-ii/
 * */

#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using std::vector;

namespace V1 {
/*
 * Solution taken from educative
 *
 * Sort intervals in ascending order by start time. Maintain set of active meetings, using priority queue top of the queue is
 * value of smallest end time.
 *
 * Time (NlogN)
 * Space (N)
 * */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto comparator = []( const auto & interval1, const auto & interval2 ) {
            return interval1[ 0 ] < interval2[ 0 ];
        };

        std::sort( intervals.begin(), intervals.end(), comparator );

        int maxRooms = 0;
        std::priority_queue< int, std::vector< int >, std::greater<> > minHeap;

        for( const auto& interval: intervals ) {
            while( !minHeap.empty() && interval[ 0 ] >= minHeap.top() ) {
                minHeap.pop();
            }

            minHeap.push( interval[ 1 ] );

            maxRooms = std::max( maxRooms, static_cast< int >( minHeap.size() ) );
        }

        return maxRooms;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    using Interval = std::vector< int >;

    int minMeetingRooms(vector<vector<int>>& intervals) {
        auto startComparator = []( const auto & interval1, const auto & interval2 ) {
            return interval1[ 0 ] < interval2[ 0 ];
        };

        auto endComparator = []( const Interval& interval1, const Interval& interval2 ) {
            return interval1[ 1 ] > interval2[ 1 ];
        };

        std::sort( intervals.begin(), intervals.end(), startComparator );

        int maxRooms = 0;
        std::vector< Interval > minHeap;

        for( const auto& interval: intervals ) {
            while( !minHeap.empty() && interval[ 0 ] >= minHeap.front()[ 1 ] ) {
                std::pop_heap( minHeap.begin(), minHeap.end(), endComparator );
                minHeap.pop_back();
            }

            minHeap.push_back( interval );
            std::push_heap( minHeap.begin(), minHeap.end(), endComparator );

            maxRooms = std::max( maxRooms, static_cast< int >( minHeap.size() ) );
        }

        return maxRooms;
    }
};
} // namespace V2

namespace V3 {
/*
 * Good explanation, taken from: https://leetcode.com/problems/meeting-rooms-ii/discuss/203658/HashMapTreeMap-resolves-Scheduling-Problem
 *
 * 1) Load all intervals to a map, the key is time point, value accumulate changes in this time. Map guarantees order of time point in chronological consequence
 * 2) To populate map need follow rules: if a new interval starts increase value at this time, if a interval ends ends decrease value at this time
 * 3) Iterate through map, and keep tracking of number active rooms, and a number of max active rooms so far.
 *
 * N - number of intervals
 * Time (NlogN) - to load all intervals to a map
 * Space (N) - store all intervals
 * */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::map< int, int > intervalChanges;
        for( const auto& interval: intervals ) {
            ++intervalChanges[ interval[ 0 ] ];
            --intervalChanges[ interval[ 1 ] ];
        }

        int maxActiveRooms = 0;
        int currentActiveRooms = 0;

        for( auto [ /*timePoint*/_, changes ] : intervalChanges ) {
            currentActiveRooms += changes;
            maxActiveRooms = std::max( maxActiveRooms, currentActiveRooms );
        }

        return maxActiveRooms;
    }
};
} // namespace V3
