/*
https://leetcode.com/problems/is-graph-bipartite/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
BFS
0 - uncolored
1 - default color
-1 - another color

V - number of nodes, graph.size
E - number of edges

Time O(V + E)
Space O(V)
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int size = graph.size();

        std::vector< int > colors( size );
        for( int i = 0; i < size; ++i ) {
            if( colors[ i ] != 0 )
                continue;

            std::queue< int > todo;
            todo.push( i );
            colors[ i ] = 1;
            while( ! todo.empty() ) {
                const int vertex = todo.front();
                todo.pop();

                for( int adj : graph[ vertex ] ) {
                    if( colors[ adj ] == 0 ) {
                        colors[ adj ] = -colors[ vertex ];
                        todo.push( adj );
                    }
                    else if( colors[ adj ] == colors[ vertex ] ) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
} // namespace
