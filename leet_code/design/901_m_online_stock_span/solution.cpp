/*
https://leetcode.com/problems/online-stock-span/
*/

#include <stack>

namespace {
/*
N - number of calls to StockSpanner.next

Time O(N)
Space O(N)
*/
class StockSpanner {
    std::stack< std::pair< int, int > > data;

public:
    StockSpanner() {
        
    }

    int next(int price) {
        int ans = 1;
        while( ! data.empty() && data.top().first <= price ) {
            ans += data.top().second;
            data.pop();
        }
        data.emplace( price, ans );
        return ans;
    }
};
} // namespace
