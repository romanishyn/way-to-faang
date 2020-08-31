/*
https://leetcode.com/problems/find-right-interval/
*/

#include <vector>
#include <map>

using std::vector;

namespace {
/*
1) Fill a map with values <start, idx>
2) Iterate over intervals and look up lower_bound for end
3) If we find element then assing it->second to the result, otherwise move on to the next interval

N - size of intervals

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        const int size = intervals.size();
        std::map< int, int > startToIdx;
        for( int i = 0; i < size; ++i ) {
            startToIdx.emplace( intervals[ i ][ 0 ], i );
        }

        std::vector< int > result( size, -1 );
        for( int i = 0; i < size; ++i ) {
            auto it = startToIdx.lower_bound( intervals[ i ][ 1 ] );
            if( it != startToIdx.end() )
                result[ i ] = it->second;
        }

        return result;
    }
};
} // namespace