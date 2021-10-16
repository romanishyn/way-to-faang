/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include <vector>
#include <limits>

using std::vector;

namespace {
/*
N - prices.size

Time O(N)
Space O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for( int i = 1; i < prices.size(); ++i ) {
            profit += std::max( 0, prices[ i ] - prices[ i - 1 ] );
        }
        
        return profit;
    }
};
} // namespace