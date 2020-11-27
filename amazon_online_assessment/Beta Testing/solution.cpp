/*
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/

#include <vector>

using std::vector;

namespace {
/*
DP + Memo

N - jobDifficulty.size
D - d

Time O(N*N*D) - ?
Space O(N*D)
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if( jobDifficulty.size() < d )
            return -1;

        std::vector< std::vector< int > > memo( jobDifficulty.size(), std::vector< int >( d + 1, -1 ) );
        return minDifficulty( jobDifficulty, 0/*idx*/, d, memo );
    }

private:
    int minDifficulty( const vector<int>& jobDifficulty, int idx, int d, std::vector< std::vector< int > >& memo ) {
        const int size = jobDifficulty.size();
        constexpr int maxInt = std::numeric_limits< int >::max();

        if( idx == size && d == 0 )
            return 0;
        if( idx == size || d == 0 )
            return maxInt;

        if( memo[ idx ][ d ] != - 1 )
            return memo[ idx ][ d ];

        int maxDay = 0;
        int result = maxInt;
        for( int i = idx; i < size; ++i ) {
            maxDay = std::max( maxDay, jobDifficulty[ i ] );
            int temp = minDifficulty( jobDifficulty, i + 1, d - 1, memo );
            if( temp != maxInt )
                result = std::min( result, temp + maxDay );
        }

        return memo[ idx ][ d ] = result;
    }
};
} // namespace
