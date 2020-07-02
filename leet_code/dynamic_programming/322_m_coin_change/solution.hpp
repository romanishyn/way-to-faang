/*
https://leetcode.com/problems/coin-change/
*/

#pragma once

#include <vector>
#include <unordered_map>

using std::vector;

namespace V1 {
/*
 * N - total amount of money (amount)
 * C - a number of coins
 *
 * Time (N^C) - exponential
 * Space (N) - height of tree, in case of subtract from amount minus one until amount is zero
 * */
class Solution {
public:
    int coinChange( vector< int > & coins, int amount ) {
        if( amount < 0 )
            return -1;
        if( amount == 0 )
            return 1;

        int result = -2;

        for( int coin : coins ) {
            int temp = coinChange( coins, amount - coin );
            if( temp != -1 ) {
                result = result < 0 ? temp : std::min( result, temp );
            }
        }

        return result + 1;
    }
};
} // namespace V1

// TODO: DP: recursion + memoization
namespace V2 {
class Solution {
public:
    int coinChange( vector< int > & coins, int amount ) {

    }
};
} // namespace V2

namespace V3 {
/*
 * DP approach
 *
 * N - total amount of money (amount)
 * C - a number of coins
 *
 * Time (N*C)
 * Space (N)
 * */
class Solution {
public:
    int coinChange( vector< int > & coins, int amount ) {
        vector< int > dp( amount + 1, amount + 1 );
        dp[ 0 ] = 0;

        for( int i = 0; i < dp.size(); ++i ) {
            for( int coin : coins ) {
                if( i >= coin )
                    dp[ i ] = std::min( dp[ i ], dp[ i - coin ] + 1 );
            }
        }

        return dp.back() > amount ? -1 : dp.back();
    }
};
} // namespace V3
