/*
 * https://leetcode.com/problems/coin-change-2/
 */

#include <vector>

using std::vector;

namespace V1 {
/*
 * Time Limit Exceeded
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return changeImpl( amount, coins, 0 );
    }

    int changeImpl( int amount, vector<int>& coins, int idx ) {
        if( amount < 0 )
            return 0;
        if( amount == 0 )
            return 1;

        int result = 0;
        for( int i = idx; i < coins.size(); ++i )
            result += changeImpl( amount - coins[ i ], coins, i );

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * C - size of coins
 * N - amount
 *
 * Time (C*N)
 * Space (C*N)
 * */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector< vector< int > > dp( coins.size() + 1, vector< int >( amount + 1 ) );

        for( auto& row : dp )
            row[ 0 ] = 1;

        for( int row = 1; row < dp.size(); ++row ) {
            const int coin = coins[ row - 1 ];

            for( int col = 1; col < dp[ 0 ].size(); ++col ) {
                if( col - coin < 0 )
                    dp[ row][ col ] = dp[ row - 1 ][ col ];
                else
                    dp[ row ][ col ] = dp[ row - 1 ][ col ] + dp[ row ][ col - coin ];
            }
        }

        return dp.back().back();
    }
};
} // namespace V2
