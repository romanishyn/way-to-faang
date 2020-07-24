/*
 * https://leetcode.com/problems/k-closest-points-to-origin/
 * */

#include <vector>
#include <queue>

using std::vector;

namespace V1 {
/*
 * Good video from BtB SWE: https://www.youtube.com/watch?v=hGK_5n81drs
 *
 * Solution based on QuickSelect algorithm
 *
 * N - size of points;
 *
 * Time (N)
 * Space (1) if ignoring vector for output result, otherwise O(N)
 * */
class Solution {

    using Point = vector< int >;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        const int size = points.size();

        int left = 0;
        int right = size - 1;

        while( true ) {
            const int pivotIdx = right;
            const int finalIdxOfChosenPivot = partition( points, left, right, pivotIdx );

            if( finalIdxOfChosenPivot == K - 1 )
                break;

            if( finalIdxOfChosenPivot < K - 1 )
                left = finalIdxOfChosenPivot + 1;
            else
                right = finalIdxOfChosenPivot - 1;
        }

        return { points.begin(), points.begin() + K };
    }

private:
    int partition( vector< Point >& points, int left, int right, int pivotIdx ) {
        const auto& pivotValue = points[ pivotIdx ];

        std::swap( points[ right ], points[ pivotIdx ] );

        int lesserItemsTailIdx = left;
        for( int i = left; i < right; ++i ) {
            if( compare( points[ i ], points[ pivotIdx ] ) < 0 ) {
                std::swap( points[ i ], points[ lesserItemsTailIdx ] );
                ++lesserItemsTailIdx;
            }
        }

        std::swap( points[ lesserItemsTailIdx ], points[ right ] );

        return lesserItemsTailIdx;
    }

    int compare( const Point& point1, const Point& point2 ) {
        return ( point1[ 0 ] * point1[ 0 ] + point1[ 1 ] * point1[ 1 ] )
            -   ( point2[ 0 ] * point2[ 0 ] + point2[ 1 ] * point2[ 1 ] );
    }
};
} // namespace V1

namespace V2 {
/*
 * Algorithm based on Heap sort. We will use minHeap and keep size K. This allows us at each moment get Kth element
 * from data stream.
 *
 * N - size of points
 *
 * Time (NlogK)
 * Space (K)
 * */
class Solution {

    using Point = vector< int >;

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comparator = [] ( const Point& point1, const Point& point2 ) {
            return ( point1[ 0 ] * point1[ 0 ] + point1[ 1 ] * point1[ 1 ] )
                <   ( point2[ 0 ] * point2[ 0 ] + point2[ 1 ] * point2[ 1 ] );
        };

        std::priority_queue< Point, vector< Point >, decltype( comparator ) > minHeap( comparator );

        for( const auto& point : points ) {
            minHeap.push( point );

            if( minHeap.size() > K ) {
                minHeap.pop();
            }
        }

        vector<vector<int>> result;
        while( !minHeap.empty() ) {
            result.push_back( ( minHeap.top() ) );
            minHeap.pop();
        }

        return result;
    }
};
} // namespace V2
