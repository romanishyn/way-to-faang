/*
https://leetcode.com/problems/random-pick-index/
*/

namespace {
/*
Reservoir Sampling solution

N - size of nums

Time O(N) - pick
Space O(N)
*/
class Solution {
    const std::vector< int > m_nums;

public:
    Solution(vector<int>& nums)
    : m_nums{ nums } {
        std::srand( std::time( nullptr ) );
    }

    int pick(int target) {
        int count = 0;
        int idx = 0;
        for( int i = 0; i < m_nums.size(); ++i ) {
            if( m_nums[ i ] == target ) {
                ++count;
                if( std::rand() % count == 0 )
                    idx = i;
            }
        }

        return idx;
    }
};
} // namespace