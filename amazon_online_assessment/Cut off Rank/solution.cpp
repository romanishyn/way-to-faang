/*
https://leetcode.com/discuss/interview-question/947050/Amazon-or-OA-2-or-Cut-off-Rank
https://aonecode.com/amazon-online-assessment-cutoff-ranks
*/

#include <vector>
#include <iostream>

using std::vector;

namespace {
/*
Solution based on Counting sort, since scores range are in the range [0, 100]

N - size of scores

Time O(N)
Space O(1)
*/
class Solution {
public:
    int countNumPlayerToLevelUp( int cutOffRank, const std::vector< int >& scores ) {
        constexpr int maxScore = 100;
        std::vector< int > buckets( maxScore + 1 );
        for( int score : scores )
            ++buckets[ score ];

        int players = 0;
        int currRank = 1;
        for( int i = buckets.size() - 1; i >= 0 && currRank <= cutOffRank; --i ) {
            if( buckets[ i ] != 0 ) {
                players += buckets[ i ];
                currRank += buckets[ i ];
            }
        }

        return players;
    }
};

int main() {
    Solution solution;
    std::cout << solution.countNumPlayerToLevelUp( 3, { 100, 50, 50, 25 } ) << ", expected: " << 3 << std::endl;
    std::cout << solution.countNumPlayerToLevelUp( 4, { 2,2,3,4,5 } ) << ", expected: " << 5 <<  std::endl;

    return 0;
}
} // namespace