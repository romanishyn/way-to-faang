/*
 * https://leetcode.com/problems/employee-free-time/
 * */

#include <vector>
#include <algorithm>
#include <queue>

using std::vector;

// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

namespace V1 {
/*
 * 1) Merge all intervals using MergeSort
 * 2) Find gaps (free time) in mergeList
 * 3) Return gaps
 *
 * N - number of the longest schedule
 * K - number of schedules
 *
 * Time (NlogK) - merge sort costs NlogK, we can merge two sorted list in O(N) time n is total number of intervals in two lists
 * Space (N + K) - K - takes recursion stack, N - length of array at each recursive call. And when we will be at bottom of recursion it's (N+K)
 * */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        if( schedule.empty() )
            return {};

        auto mergeList = merge( schedule, 0, schedule.size() );

        vector<Interval> result;
        for( int i = 1; i < mergeList.size(); ++i )
            result.emplace_back( mergeList[ i - 1 ].end, mergeList[ i ].start );

        return result;
    }

private:
    vector<Interval> merge( const vector<vector<Interval>>& schedule, int begin, int end ) {
        if( end - begin == 1 )
            return schedule[ begin ];

        const int mid = begin + ( end - begin ) / 2;

        return merge(
            merge( schedule, begin, mid ),
            merge( schedule, mid, end )
        );
    }

    vector<Interval> merge( const vector<Interval>& list1, const vector<Interval>& list2 ) {
        vector<Interval> intervals;
        int i = 0;
        int j = 0;
        const int sizeList1 = list1.size();
        const int sizeList2 = list2.size();
        while( i < sizeList1 || j < sizeList2 ) {
            if( i == sizeList1 )
                intervals.push_back( list2[ j++ ] );
            else if( j == sizeList2 )
                intervals.push_back( list1[ i++ ] );
            else if( list1[ i ].start < list2[ j ].start )
                intervals.push_back( list1[ i++ ] );
            else
                intervals.push_back( list2[ j++ ] );
        }

        vector< Interval > result;
        for( auto interval : intervals ) {
            if( result.empty() || result.back().end < interval.start )
                result.push_back( interval );
            else
                result.back().end = std::max( result.back().end, interval.end );
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * The idea is using iterative Divide and Conquer approach merge all schedules to one. Then find all gaps in this interval
 *
 * N - length of interval
 * K - number of schedules
 *
 * shift - это первый элемент за средним. Единицу нужно именно добавлять сразу к длине, а только потом делить попалам. это решать проблему
 * с четной и нечетной длиной, и это дает возможность получать первый эл-т за средним
 * потом нужно укаратить длину, а именно присвоить здначение сдвига, так как это действительно новая длина
 *
 * Time (NlogK) - to merge schedules need make logK merges and each merge costs N - total number of intervals in two list
 * Space (N) - return result plus to merge intervals
 * */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        if( schedule.empty() )
            return {};

        int length = schedule.size();
        while( length > 1 ) {
            int shift = ( length + 1 ) / 2;
            for( int i = 0; i < length / 2; ++i ) {
                schedule[ i ] = merge( schedule[ i ], schedule[ i + shift ] );
            }

            length = shift;
        }

        const auto& mergedList = schedule[ 0 ];
        vector<Interval> result;
        for( int i = 1; i < mergedList.size(); ++i )
            result.emplace_back( mergedList[ i - 1 ].end, mergedList[ i ].start );

        return result;
    }

private:
    vector<Interval> merge( const vector<Interval>& list1, const vector<Interval>& list2 ) {
        const int sizeList1 = list1.size();
        const int sizeList2 = list2.size();
        int idx1 = 0;
        int idx2 = 0;

        vector<Interval> intervals;
        while( idx1 < sizeList1 || idx2 < sizeList2 ) {
            if( idx1 == sizeList1 )
                intervals.push_back( list2[ idx2++ ] );
            else if( idx2 == sizeList2 )
                intervals.push_back( list1[ idx1++ ] );
            else if( list1[ idx1 ].start < list2[ idx2 ].start )
                intervals.push_back( list1[ idx1++ ] );
            else
                intervals.push_back( list2[ idx2++ ] );
        }

        vector<Interval> result;
        for( const auto& interval: intervals ) {
            if( result.empty() || result.back().end < interval.start )
                result.push_back( interval );
            else
                result.back().end = std::max( result.back().end, interval.end );
        }

        return result;
    }
};
} // namespace V2

namespace V3 {
/*
 * N -
 * */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        using HeapValue = std::pair< Interval, std::pair< int/*schedule_id*/, int/*interval_id*/ > >;

        auto comparator = []( const HeapValue& val1, const HeapValue& val2 ) {
            return val1.first.start > val2.first.start;
        };

        std::priority_queue< HeapValue, std::vector< HeapValue >, decltype( comparator ) > minHeap( comparator );

        for( int i = 0; i < schedule.size(); ++i ) {
            minHeap.push( std::make_pair( schedule[ i ].front(), std::make_pair( i, 0 ) ) );
        }

        vector< Interval > result;

        auto prevInterval = minHeap.top().first;
        while( !minHeap.empty() ) {
            auto topValue = minHeap.top();
            minHeap.pop();

            if( prevInterval.end < topValue.first.start ) {
                result.emplace_back( prevInterval.end, topValue.first.start );
                prevInterval = topValue.first;
            }
            else {
                prevInterval.end = std::max( prevInterval.end, topValue.first.end );
            }

            const int scheduleId = topValue.second.first;
            const int intervalId = topValue.second.second;
            if( schedule[ scheduleId ].size() > intervalId + 1 ) {
                minHeap.push( std::make_pair( schedule[ scheduleId ][ intervalId + 1 ], std::make_pair( scheduleId, intervalId + 1 ) ) );
            }
        }

        return result;
    }
};
} // namespace V3