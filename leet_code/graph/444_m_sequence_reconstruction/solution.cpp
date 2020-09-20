/*
https://leetcode.com/problems/sequence-reconstruction/
*/

#include <vector>
#include <unordered_map>
#include <queue>

using std::vector;

namespace {
/*
Test cases:
[1]
[]

[1]
[[1],[2,3],[3,2]]

Solution based on BFS topological sort.

V - cont of distinct number in org and seqs
E - number of edges (rules)

Time O(V + E)
Space O(V + E) store all rules for each number in adjacency list
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        std::unordered_map< int, int > inDegree;
        std::unordered_map< int, std::vector< int > > graph;

        for( const auto& seq : seqs ) {
            for( int vertex : seq ) {
                inDegree[ vertex ];
                graph[ vertex ];
            }
        }

        if( inDegree.size() != org.size() )
            return false;

        for( const auto& seq : seqs ) {
            for( int i = 1; i < seq.size(); ++i ) {
                ++inDegree[ seq[ i ] ];
                graph[ seq[ i - 1 ] ].push_back( seq[ i ] );
            }
        }

        std::vector< int > sortedOrg;
        std::queue< int > zeros;
        for( const auto& entry : inDegree ) {
            if( entry.second == 0 )
                zeros.push( entry.first );
        }

        while( zeros.size() == 1 ) {
            const int vertex = zeros.front();
            zeros.pop();
            sortedOrg.push_back( vertex );

            for( int adj : graph[ vertex ] ) {
                if( --inDegree[ adj ] == 0)
                    zeros.push( adj );
            }
        }

        return org == sortedOrg;
    }
};
} // namespace
