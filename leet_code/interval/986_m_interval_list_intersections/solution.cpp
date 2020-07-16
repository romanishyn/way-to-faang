/*
 * https://leetcode.com/problems/interval-list-intersections/
 * */

#include <vector>

using std::vector;

namespace V1 {
/*
 * Algorithm will iterate through both the lists together to see if any two interval overlap.
 * If two interval overlap, we will insert overlapped part into a result list and move on to the next
 * interval which is finished early.
 *
 * M - size of A
 * N - size of B
 *
 * Time (M + N)
 * Space (M + N)
 * */
class Solution {
public:
    using Interval = vector<int>;

    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;

        std::size_t idxA = 0;
        std::size_t idxB = 0;
        while( idxA < A.size() && idxB < B.size() ) {
            if( isOverlapping( A[ idxA ], B[ idxB ] ) )
                result.push_back( getIntersection( A[ idxA ], B[ idxB ] ) );

            if( A[ idxA ][ 1 ] < B[ idxB ][ 1 ] )
                ++idxA;
            else
                ++idxB;
        }

        return result;
    }

private:
    bool isOverlapping( const Interval& interval1, const Interval& interval2 ) {
        int end = std::min( interval1[ 1 ], interval2[ 1 ] );
        int start = std::max( interval1[ 0 ], interval2[ 0 ] );

        return end - start >= 0;
    }

    Interval getIntersection( const Interval& interval1, const Interval& interval2 ) {
        Interval interval;
        interval[ 0 ] = std::max( interval1[ 0 ], interval2[ 0 ] );
        interval[ 1 ] = std::min( interval1[ 1 ], interval2[ 1 ] );

        return interval;
    }
};
} // namespace V1
