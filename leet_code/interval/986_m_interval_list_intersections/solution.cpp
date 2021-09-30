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

namespace {
/*
N - firstList.size
M - secondList.size

Time O(N+M)
Space O(N+M)
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::vector< std::vector< int > > result;

        int a = 0;
        int b = 0;

        while( a < firstList.size() && b < secondList.size() ) {
            int begin = std::max( firstList[ a ][ 0 ], secondList[ b ][ 0 ] );
            int end = std::min( firstList[ a ][ 1 ], secondList[ b ][ 1 ] );

            if( end - begin >= 0 )
                result.push_back( { begin, end } );

            if( firstList[ a ][ 1 ] < secondList[ b ][ 1 ] )
                ++a;
            else
                ++b;
        }

        return result;
    }
};
} // namespace
