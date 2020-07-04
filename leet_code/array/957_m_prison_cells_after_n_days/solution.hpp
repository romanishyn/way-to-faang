/*
https://leetcode.com/problems/prison-cells-after-n-days/
*/

#pragma once

#include <vector>

using std::vector;

namespace V1 {
/*
 * This is like a finite state machine, on each iteration we change current state, but with time we will come back to
 * initial state. Given that we changing only 6 bits, since after the first step first and last bits are going to
 * be always zero, this is why we iterate in range from 1 to 6. For large values (N) we can expect that cycles to be
 * come over and over again, since we can only have 2^6 (64) different states.
 * Once a cycle is detected, we know that the answer is on of the elements in the 'seen' collection. We just need return
 * state with index equal to (N-1)%seen.size(), with seen.size() tell us how big is loop interval.
 * If we have not come across the cycle, return the last computed state.
 *
 * Time (1), in the worst we need to compute 64 states.
 * Space (1), in the worst case we have 64 states.
 * */
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        constexpr int cellCount = 8;

        vector< int > prev( cellCount );
        vector< vector< int > > seen;

        for( int i = 0; i < N; ++i ) {
            for( int j = 1; j < cellCount - 1; ++j ) {
                prev[ j ] = cells[ j - 1] == cells[ j + 1 ];
            }

            if( !seen.empty() && seen.front() == prev )
                return seen[ ( N - 1 ) % seen.size() ];

            cells = prev;
            seen.push_back(  prev );
        }

        return seen.back();
    }
};
} // namespace V1