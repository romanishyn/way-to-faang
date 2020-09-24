/*
https://leetcode.com/problems/gas-station/
*/

#include <vector>

using std::vector;

namespace {
/*
Start from each station and check if it is possible to finish journey.

N - number of stations

Time O(N^2)
Space O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int size = gas.size();

        for( int startPos = 0; startPos < size; ++startPos ) {
            int diff = 0;

            for( int step = 0; step < size; ++step ) {
                const int idx = ( startPos + step ) % size;

                diff += gas[ idx ] - cost[ idx ];
                if( diff < 0 )
                    break;
            }

            if( diff >= 0 )
                return startPosl
        }

        return -1;
    }
};
} // namespace

namespace {
/*
Greedy approach

N - number of stations

Time O(N)
Space O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTunk = 0;
        int currTunk = 0;
        int startPosition = 0;

        for( int i = 0; i < gas.size(); ++i ) {
            totalTunk += gas[ i ] - cost[ i ];
            currTunk += gas[ i ] - cost[ i ];

            if( currTunk < 0 ) {
                currTunk = 0;
                startPosition = i + 1;
            }
        }

        return totalTunk >= 0 ? startPosition : -1;
    }
};
} // namespace