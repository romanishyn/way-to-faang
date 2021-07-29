/*
https://leetcode.com/problems/critical-connections-in-a-network/
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::vector;

namespace {
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        std::unordered_map< int, int > inDegree;
        std::unordered_map< int, std::unordered_set< int > > graph;

        // init
        for( int i = 0; i < n; ++i ) {
            inDegree[ i ];
            graph[ i ];
        }

        // populate
        for( const auto& edge: connections ) {
            ++inDegree[ edge[ 0 ] ];
            ++inDegree[ edge[ 1 ] ];

            graph[ edge[ 0 ] ].insert( edge[ 1 ] );
            graph[ edge[ 1 ] ].insert( edge[ 0 ] );
        }

        std::unordered_set< int > seen;
        std::queue< int > sourses;
        for( auto [ vertex, degree ] : inDegree ) {
            if( degree >= 1 ) {
                sourses.push( vertex );
                seen.push( vertex );
            }
        }

        std::vector< std::vector< int > > resultConnections;

        while( ! sourses.empty() ) {
            auto vertex = sourses.front();
            sourses.pop();

            if( ! graph[ vertex ].empty( ) ) {
                auto targetVertex = graph[ vertex ].front();
                resultConnections.push_back( { vertex, targetVertex } );
            }

            for( auto adj : graph[ vertex ] ) {
                --inDegree[ adj ];
                if( inDegree[ adj ] == 1 && seen.insert( adj ).second ) {
                    sourses.push( adj );
                }
            }

            graph[ vertex ].erase( targetVertex );
            graph[ targetVertex ].erase( vertex );
        }

        return resultConnections;
    }
};
} // namespace