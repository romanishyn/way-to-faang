/*
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

30,20,150,100,40

res: 3
30: 2
20: 1
40: 2

[60,60,60]
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        std::unordered_map< int, int > remainders;

        for( int t : time ) {
            const int remainder = t % 60;
            const int findRemainder = remainder == 0 ? 0 : 60 - remainder;

            if( auto it = remainders.find( findRemainder ); it != remainders.end() ) {
                result += it->second;
            }
            ++remainders[ remainder ];
        }

        return result;
    }
};
} // namespace

namespace {
/*

*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;
        std::array< int, 60 > remainders{};
        
        for( int t : time ) {
            if( t % 60 == 0 ) {
                result += remainders[ 0 ];
            }
            else {
                result += remainders[ 60 - t % 60 ];
            }
            ++remainders[ t % 60 ];
        }

        return result;
    }
};
} // namespace
