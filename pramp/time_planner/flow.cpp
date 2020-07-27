/*

A: ***** ****  *****   *****
B: -- ---  --     -----
C:     --  -------  --     -----
D:

[10, 50] [51, 70]

1) sorted by start time
2) not overlped
3)

while( idxA < sizeA && idxB < sizeB )

                     idxA
slotsA = [[10, 50], [60, 120], [140, 210]]

60, 70
[60, 68]
                    idxB
slotsB = [[0, 15], [60, 70]]
dur = 8

*/

using Interval = vector<int>;

Interval getIntersection( const Interval& interval1, const Interval& interval2 ) {
    const int end = std::min( interval1[ 1 ], interval2[ 1 ] );
    const int start = std::max( interval1[ 0 ], interval2[ 0 ] );

    return { start, end };
}

vector<int> meetingPlanner( const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) {
    int idxA = 0;
    int idxB = 0;
    while( idxA < slotsA.size() && idxB < slotsB.size() ) {
        auto interval = getIntersection( slotsA[ idxA ], slotsB[ idxB ] );
        if( interval[ 1 ] - interval[ 0 ] >= dur ) {
            interval[ 1 ] = interval[ 0 ] + dur;
            return interval;
        }
        if( slotsA[ idxA ][ 1 ] < slotsB[ idxB ][ 1 ] )
            ++idxA;
        else
            ++idxB;
    }

    return {};
}

int main() {
    return 0;
}