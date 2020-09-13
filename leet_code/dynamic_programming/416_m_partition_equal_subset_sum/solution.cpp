/*
https://leetcode.com/problems/partition-equal-subset-sum/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
Recursive Top-Down
LC - TLE

N - size of nums

Time O(2^N)
Space O(N)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1 )
            return false;

        int sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( sum & 1 )
            return false;

        return canPartion( nums, 0, sum / 2 );
    }

private:
    bool canPartion( const std::vector< int >& nums, int numIdx, int remainingSum ) {
        if( remainingSum == 0 )
            return true;
        if( nums.size() == numIdx )
            return false;

        if( remainingSum >= nums[ numIdx ] ) {
            if( canPartion( nums, numIdx + 1, remainingSum - nums[ numIdx ] ) )
                return true;
        }
 
        return canPartion( nums, numIdx + 1, remainingSum );
    }
};
} // namespace

namespace {
/*
Top-Down DP with Memoization

N - size of nums
S - sum of nums

Time O(N*S)
Space O(N*S)
*/
class Solution {
    using Memo = std::vector< std::vector< int > >;

public:
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1 )
            return false;

        int sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( sum & 1 )
            return false;

        sum /= 2;

        Memo memo( nums.size(), std::vector< int >( sum + 1, -1 ) );
        return canPartition( memo, nums, 0, sum );
    }

private:
    bool canPartition( Memo& memo, const std::vector< int >& nums, int numIdx, int remainingSum ) {
        if( remainingSum == 0 )
            return true;
        if( nums.size() == numIdx )
            return false;
        if( memo[ numIdx ][ remainingSum ] != -1 )
            return memo[ numIdx ][ remainingSum ];

        if( remainingSum >= nums[ numIdx ] ) {
            memo[ numIdx ][ remainingSum ] = canPartition( memo, nums, numIdx + 1, remainingSum - nums[ numIdx ] );
            if( memo[ numIdx ][ remainingSum ] )
                return memo[ numIdx ][ remainingSum ];
        }

        memo[ numIdx ][ remainingSum ] = canPartition( memo, nums, numIdx + 1, remainingSum );
        return memo[ numIdx ][ remainingSum ];
    }
};
} // namespace

namespace {
/*
Bottom-Up

N - size of nums
S - sum of nums

Time O(N*S)
Space O(N*S)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1 )
            return false;

        int sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( sum & 1 )
            return false;

        sum /= 2;

        std::vector< std::vector< bool > > dp( nums.size(), std::vector< bool >( sum + 1 ) );
        for( int i = 0; i < dp.size(); ++i )
            dp[ i ][ 0 ] = true;

        for( int j = 1; j < dp[ 0 ].size(); ++j ) {
            if( nums[ 0 ] == j )
                dp[ 0 ][ j ] = true;
        }

        for( int i = 1; i < dp.size(); ++i ) {
            for( int sum = 1; sum < dp[ 0 ].size(); ++sum ) {
                if( dp[ i - 1 ][ sum ] ) {
                    dp[ i ][ sum ] = dp[ i - 1 ][ sum ];
                }
                else if ( sum >= nums[ i ] ) {
                    dp[ i ][ sum ] = dp[ i - 1 ][ sum - nums[ i ] ];
                }
            }
        }

        return dp.back().back();
    }
};
} // namespace

namespace {
/*
Bottom-Up

N - size of nums
S - sum of nums

Time O(N*S)
Space O(S)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if( nums.size() <= 1 )
            return false;

        int sum = std::accumulate( nums.begin(), nums.end(), 0 );
        if( sum % 2 == 1 )
            return false;

        sum /= 2;
        std::vector< bool > dp( sum + 1 );
        dp[ 0 ] = true;

        if( nums[ 0 ] < dp.size() )
            dp[ nums[ 0 ] ] = true;

        for( int i = 1; i < nums.size(); ++i ) {
            for( int s = sum; s >= 1; --s ) {
                if( s >= nums[ i ] )
                    dp[ s ] = dp[ s ] || dp[ s - nums[ i ] ];
            }
        }

        return dp.back();
    }
};
} // namespace