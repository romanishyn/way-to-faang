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
        std::swap( points[ right ], points[ pivotIdx ] );

        const auto& pivotValue = points[ right ];

        int lesserItemsTailIdx = left;
        for( int i = left; i < right; ++i ) {
            if( compare( points[ i ], pivotValue ) < 0 ) {
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

namespace {
/*
N - points.size
K - k

Time O(NlogK)
Space O(K)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](const auto& lhs, const auto& rhs) {
            const int dist1 = lhs[ 0 ] * lhs[ 0 ] + lhs[ 1 ] * lhs[ 1 ];
            const int dist2 = rhs[ 0 ] * rhs[ 0 ] + rhs[ 1 ] * rhs[ 1 ];
            
            return dist1 < dist2;
        };
        
        std::priority_queue< std::vector< int >, std::vector< std::vector< int > >, decltype( comparator ) > maxHeap( comparator );
        
        for( int i = 0; i < k; ++i )
            maxHeap.push( points[ i ] );
        
        for( int i = k; i < points.size(); ++i ) {
            maxHeap.push( points[ i ] );
            maxHeap.pop();
        }
            
        std::vector< std::vector< int > > result;
        while( ! maxHeap.empty() ) {
            result.push_back( maxHeap.top() );
            maxHeap.pop();
        }
        
        return result;
    }
};
} // namespace


namespace {
/*
N - points.size
K - k

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int size = points.size();
        
        int left = 0;
        int right = size - 1;
        
        while( left <= right ) {
            int pivotIdx = right;
            pivotIdx = partition( points, left, right, pivotIdx );
            
            if( pivotIdx == k - 1 )
                break;
            else if( pivotIdx > k - 1 )
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
        
        
        return { points.begin(), std::next( points.begin(), k ) };
    }
    
private:
    int partition( std::vector< std::vector< int > > & points, int left, int right, int pivotIdx ) {
        std::swap( points[ pivotIdx ], points[ right ] );
        const auto & pivotValue = points[ right ];
        
        int lessThanPivotValIdx = left;
        
        auto comparator = [] ( const auto& lhs, const auto& rhs ) {
            const int dist1 = lhs[ 0 ] * lhs[ 0 ] + lhs[ 1 ] * lhs[ 1 ];
            const int dist2 = rhs[ 0 ] * rhs[ 0 ] + rhs[ 1 ] * rhs[ 1 ];
            
            return dist1 < dist2;
        };
        
        for( int i = left; i < right; ++i ) {
            if( comparator( points[ i ], pivotValue ) ) {
                std::swap( points[ lessThanPivotValIdx ], points[ i ] );
                ++lessThanPivotValIdx;
            }
        }
        
        std::swap( points[ right ], points[ lessThanPivotValIdx ] );
        
        return lessThanPivotValIdx;
    }    
};
} // namespace