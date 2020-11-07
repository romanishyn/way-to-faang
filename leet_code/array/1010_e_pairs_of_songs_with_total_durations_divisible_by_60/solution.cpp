/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
N - size of time

Time O(N)
Space O(N)
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        std::unordered_map< int, int > remainderToFreq;
        for( int t : time ) {
            const int simplifiedTime = t % 60;
            const int searchRemainder = simplifiedTime == 0 ? 0 : 60 - simplifiedTime;
            if( auto it = remainderToFreq.find( searchRemainder ); it != remainderToFreq.end() )
                result += it->second;

            ++remainderToFreq[ simplifiedTime ];
        }

        return result;
    }
};
} // namespace
