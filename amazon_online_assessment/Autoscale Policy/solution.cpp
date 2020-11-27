/*
https://leetcode.com/discuss/interview-question/376019/
*/

#include <vector>

namespace {
/*
N - size of averageUtil

Time O(N)
Space (1)
*/
class Solution {
public:
    int finalInstances( int instances, const std::vector< int >& averageUtil ) {
        const int idle = 10;

        int idx = 0;
        while( idx < averageUtil.size() ) {
            const int util = averageUtil[ idx ];
            if( util > 60 && instances * 2 <= 100'000'000 ) {
                instances *= 2;
                idx += idle;
            }
            else if( util < 25 && instances > 1 ) {
                instances /= 2;
                idx += idle;
            }

            ++idx;
        }

        return instances;
    }
}; // class Solution
} // namespace
