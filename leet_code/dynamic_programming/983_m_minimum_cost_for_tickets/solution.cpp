/*
https://leetcode.com/problems/minimum-cost-for-tickets/
*/

namespace {
/*
Generate all possible variotion of buing tickets/

N - length of days
C - equals 3

Time O(N^C)
Space O(N)
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int minCost = std::numeric_limits< int >::max();
        findMinCost( days, costs, 0, minCost, 0, -1 );
        return minCost;
    }

    void findMinCost( const vector< int >& days, const vector< int >& costs, int dayIdx, int& minCost, int currCost, int endDay ) {
        if( days.size() == dayIdx ) {
            minCost = std::min( minCost, currCost );
            return;
        }
        if( days[ dayIdx ] <= endDay ) {
            findMinCost( days, costs, dayIdx + 1, minCost, currCost, endDay );
        }
        else {
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 0 ], days[ dayIdx ] );
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 1 ], days[ dayIdx ] + 7 - 1 );
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 2 ], days[ dayIdx ] + 30 - 1 );
        }
    }
};
} // namespace

namespace {
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int minCost = std::numeric_limits< int >::max();
        findMinCost( days, costs, 0, minCost, 0, -1 );
        return minCost;
    }

    void findMinCost( const vector< int >& days, const vector< int >& costs, int dayIdx, int& minCost, int currCost, int endDay ) {
        if( days.size() == dayIdx ) {
            minCost = std::min( minCost, currCost );
            return;
        }
        if( days[ dayIdx ] <= endDay ) {
            findMinCost( days, costs, dayIdx + 1, minCost, currCost, endDay );
        }
        else {
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 0 ], days[ dayIdx ] );
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 1 ], days[ dayIdx ] + 7 - 1 );
            findMinCost( days, costs, dayIdx + 1, minCost, currCost + costs[ 2 ], days[ dayIdx ] + 30 - 1 );
        }
    }
};
} // namespace