#pragma once

#include <vector>
#include <limits>

using std::vector;

class Solution {
public:
//    int maxProfit(vector<int>& prices) {
//        int profit = 0;
//        const int size = prices.size();
//        for( int i = 0; i < size; ++i ) {
//            for( int j = i + 1; j < size; ++j ) {
//                const int tempProfit = prices[j] - prices[i];
//                if( tempProfit > profit )
//                    profit = tempProfit;
//            }
//        }
//
//        return profit;
//    }

//    int maxProfit(vector<int>& prices) {
//        int cheapest = std::numeric_limits< int >::max();
//        int profit = 0;
//
//        const int size = prices.size();
//        for( int i = 1; i < size; ++i ) {
//            const int prevPrice = prices[ i - 1 ];
//            if( cheapest > prevPrice )
//                cheapest = prevPrice;
//
//            const int tempProfit = prices[ i ] - cheapest;
//            if( tempProfit > profit )
//                profit = tempProfit;
//        }
//
//        return profit;
//    }

    int maxProfit(vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max();
        int profit = 0;

        const int size = prices.size();
        for( int i = 1; i < size; ++ i ) {
            minPrice = std::min( minPrice, prices[ i - 1 ] );
            profit = std::max( profit, prices[ i ] - minPrice );
        }

        return profit;
    }
};
