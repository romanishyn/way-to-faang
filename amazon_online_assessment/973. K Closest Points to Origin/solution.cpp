/*
https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include <vector>
#include <crand>

using std::vector;

namespace {
/*
N - size of points

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int left = 0;
        int right = points.size() - 1;
        int pivotIdx = left;

        while( true ) {
            pivotIdx = left + ( std::rand() % ( right - left + 1 ) );
            pivotIdx = partition( points, left, right, pivotIdx );

            if( K == pivotIdx + 1 )
                break;

            if( K < pivotIdx + 1 )
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }

        return { begin( points ), std::next( begin( points ), K ) };
    }

private:
    int partition( vector<vector<int>>& points, int left, int right, int pivot ) {
        const auto pivotValue = points[ pivot ];
        std::swap( points[ right ], points[ pivot ] );

        int itemsLesserThenPivot = left;
        for( int i = left; i < right; ++i ) {
            if( areLess( points[ i ], pivotValue ) ) {
                std::swap( points[ itemsLesserThenPivot ], points[ i ] );
                ++itemsLesserThenPivot;
            }
        }

        std::swap( points[ itemsLesserThenPivot ], points[ right ] );

        return itemsLesserThenPivot;
    }

    bool areLess( const std::vector< int >& point1, const std::vector< int >& point2 ) {
        return  ( point1[ 0 ] * point1[ 0 ] + point1[ 1 ] * point1[ 1 ] )
            <   ( point2[ 0 ] * point2[ 0 ] + point2[ 1 ] * point2[ 1 ] );
    }
};
} // namespace