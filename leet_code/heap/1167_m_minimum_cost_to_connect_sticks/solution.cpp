/*
https://leetcode.com/problems/minimum-cost-to-connect-sticks/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
We will follow greedy approach to connect the shortest sticks will ensure lowert cost.
To perform this, we gonna use minHeap.
1) Init minHeap with all values from sticks
2) While min heap size greater than 1 take two values from heap sum up them, add sum to the result and push sum to the heap

N - length of sticks

Time O(NlogN)
Space O(N)
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int cost = 0;
        std::priority_queue< int, std::vector< int >, std::greater< int > > minHeap{ sticks.begin(), sticks.end() };

        while( minHeap.size() > 1 ) {
            int stick1 = minHeap.top();
            minHeap.pop();
            int stick2 = minHeap.top();
            minHeap.pop();
            int stick3 = stick1 + stick2;
            cost += stick3;
            minHeap.push( stick3 );
        }

        return minHeap;
    }
};
} // namespace