/*
https://leetcode.com/problems/teemo-attacking/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of timeSeries

Time O(N)
Space O(1)
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if( timeSeries.empty() )
            return 0;

        int result = duration;
        for( int i = timeSeries.size() - 2; i >= 0; --i ) {
            result += std::min( timeSeries[ i + 1 ] - timeSeries[ i ], duration );
        }

        return result;
    }
};
} // namespace
