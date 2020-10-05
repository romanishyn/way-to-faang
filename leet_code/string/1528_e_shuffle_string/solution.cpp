/*
https://leetcode.com/problems/shuffle-string/
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace {
/*
Cycle sort

N - size of indices or s

Time O(N)
Space O(1)
*/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i = 0;
        while( i < indices.size() ) {
            int j = indices[ i ];
            if( indices[ i ] != indices[ j ] ) {
                std::swap( s[ i ], s[ j ] );
                std::swap( indices[ i ], indices[ j ] );
            }
            else {
                ++i;
            }
        }

        return s;
    }
};
} // namespace

namespace {
/*
Cycle sort

N - size of indices or s

Time O(N)
Space O(1)
*/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int i = 0;
        while( i < indices.size() ) {
            if( indices[ i ] != i ) {
                std::swap( s[ i ], s[ indices[ i ] ] );
                std::swap( indices[ i ], indices[ indices[ i ] ] );
            }
            else {
                ++i;
            }
        }

        return s;
    }
};
} // namespace