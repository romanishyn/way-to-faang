/*
https://leetcode.com/problems/minimum-height-trees/
*/

#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;

namespace {
/*
Find middle of longest path in tree

N - n

Time O(N)
Space O(N)
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if( n == 1 )
            return { 0 };

        std::vector< std::vector< int > > graph( n );
        std::vector< int > inDegree( n );

        for( const auto& edge : edges ) {
            graph[ edge[ 0 ] ].push_back( edge[ 1 ] );
            graph[ edge[ 1 ] ].push_back( edge[ 0 ] );

            ++inDegree[ edge[ 0 ] ];
            ++inDegree[ edge[ 1 ] ];
        }

        std::deque< int > leaves;
        for( int i = 0; i < inDegree.size(); ++i ) {
            if( inDegree[ i ] == 1 )
                leaves.push_back( i );
        }

        while( n > 2 ) {
            const int leafCount = leaves.size();
            n -= leafCount;

            for( int i= 0; i < leafCount; ++i ) {
                int nodeId = leaves.front();
                leaves.pop_front();

                for( int adj : graph[ nodeId ] ) {
                    if( --inDegree[ adj ] == 1 )
                        leaves.push_back( adj );
                }
            }
        }

        return { leaves.begin(), leaves.end() };
    }
};
} // namespace