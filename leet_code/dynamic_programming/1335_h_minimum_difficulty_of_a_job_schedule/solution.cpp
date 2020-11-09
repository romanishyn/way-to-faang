/*
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/

#include <vector>
#include <limits>

using std::vector;

namespace {
/*
DP, memo

N - size of jobDifficulty
D - d

Time O(N*N*D)
Space O(N*D)
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int size = jobDifficulty.size();
        if( d > size )
            return -1;

        std::vector< std::vector< int > > memo( size, std::vector< int >( d + 1, -1 ) );
        return minDifficulty( jobDifficulty, 0, d, memo );
    }

private:
    int minDifficulty(
        const std::vector< int > & jobDifficulty,
        int idx,
        int d,
        std::vector< std::vector< int > >& memo )
    {
        constexpr int maxInt = std::numeric_limits< int >::max();
        const int size = jobDifficulty.size();

        if( idx == size && d == 0 )
            return 0;
        if( idx == size || d == 0 )
            return maxInt;

        if( memo[ idx ][ d ] != -1 )
            return memo[ idx ][ d ];

        int currMax = -1;
        int result = maxInt;
        for( int i = idx; i < size; ++i ) {
            currMax = std::max( currMax, jobDifficulty[ i ] );

            const int temp = minDifficulty( jobDifficulty, i + 1, d - 1, memo );
            if( temp != maxInt )
                result = std::min( result, currMax + temp );
        }

        return memo[ idx ][ d ] = result;
    }
};
} // namespace
