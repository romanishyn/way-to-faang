/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

#include <vector>
#include <limits>

using std::vector;

namespace {
/*
LC:  Time Limit Exceeded

We can spend at most two transatcion. To use this knowlign we can use device and conqer approach.
Each subarray we handle like "Buy and sell stocks I", and then define maximum profit so far.

N - size of prices

Time (N^2), for sequence of length N, we would have N possible divisions, each of the elements would be visited once in each divisions
Space (1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        const int size = prices.size();
        for( int i = 0; i < size; ++i ) {
            const int leftProfit = maxProfit( prices, 0, i );
            const int rightProfit = maxProfit( prices, i, size );

            profit = std::max( { profit, leftProfit + rightProfit } );
        }

        return profit;
    }

private:
    int maxProfit( const std::vector< int > & prices, int begin, int end ) {
        int profit = 0;
        int minPrice = std::numeric_limits< int >::max();

        for( int i = begin; i < end; ++i ) {
            minPrice = std::min( minPrice, prices[ i ] );
            profit = std::max( profit, prices[ i ] - minPrice );
        }

        return profit;
    }
};
} // namespace

namespace {
/*
N - length of prices;

Time O(N)
Space O(N)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if( size <= 1 )
            return 0;

        std::vector< int > left( size );
        std::vector< int > right( size );

        int leftMin = prices.front();
        int rightMax = prices.back();

        for( int l = 1; l < size; ++l ) {
            left[ l ] = std::max( left[ l - 1 ], prices[ l ] - leftMin );
            leftMin = std::min( leftMin, prices[ l ] );

            int r = size - l - 1;
            right[ r ] = std::max( right[ r + 1 ], rightMax - prices[ r ] );
            rightMax = std::max( rightMax, prices[ r ] );
        }

        int profit = right[ 0 ];
        for( int i = 0; i < size - 1; ++i ) {
            profit = std::max( profit, left[ i ] + right[ i + 1 ] );
        }

        return profit;
    }
};
} // namespace