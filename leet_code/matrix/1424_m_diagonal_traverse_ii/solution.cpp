/*
https://leetcode.com/problems/diagonal-traverse-ii/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
N - number of rows
M - length of max row

Time O(N*M)
Space O(N*M)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector< vector< int > > diagonals;

        for( int i = 0; i < nums.size(); ++i ) {
            for( int j = 0; j < nums[ i ].size(); ++j ) {
                const int diagonalIdx = i + j;
                if( diagonalIdx >= diagonals.size() )
                    diagonals.resize( diagonalIdx + 1 );

                diagonals[ diagonalIdx ].push_back( nums[ i ][ j ] );
            }
        }
 
        vector< int > result;
        for( int i = 0; i < diagonals.size(); ++i ) {
            for( int j = diagonals[ i ].size() - 1; j >= 0; --j )
                result.push_back( diagonals[ i ][ j ] );
        }

        return result;
    }
};
} // namespace

namespace {
/*
BFS

N - number of rows
M - length of max row

Time O(N*M)
Space O(N) - ?
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        std::queue< std::pair< int, int > > diagonals;
        diagonals.emplace( 0, 0 );

        std::vector< int > result;

        while( ! diagonals.empty() ) {
            auto [ i, j ] = diagonals.front();
            diagonals.pop();

            result.push_back( nums[ i ][ j ] );

            if( j == 0 && i + 1 < nums.size() )
                diagonals.emplace( i + 1, j );

            if( j + 1 < nums[ i ].size() )
                diagonals.emplace( i, j + 1 );
        }

        return result;
    }
};
} // namespace