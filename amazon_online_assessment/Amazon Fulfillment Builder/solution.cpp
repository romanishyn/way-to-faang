/*
https://leetcode.com/discuss/interview-question/344677
https://leetcode.com/problems/minimum-cost-to-connect-sticks/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
N - size of sticks

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        std::priority_queue< int, std::vector< int >, std::greater< int > > queue( std::greater< int >{}, sticks );

        int result = 0;
        while( queue.size() > 1 ) {
            const int stick1 = queue.top();
            queue.pop();
            const int stick2 = queue.top();
            queue.pop();

            const int stick3 = stick1 + stick2;
            result += stick3;
            queue.push( stick3 );
        }

        return result;
    }
};
} // namespace