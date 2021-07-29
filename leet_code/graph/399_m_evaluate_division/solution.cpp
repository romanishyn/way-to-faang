/*
https://leetcode.com/problems/evaluate-division/
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::string;

namespace {
class Solution {
    using Graph = std::unordered_map< std::string, std::unordered_map< std::string, double > >;

public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries)
    {
        Graph graph;

        // build graph
        for( int i = 0; i < equations.size(); ++i ) {
            graph[ equations[ i ][ 0 ] ].try_emplace( equations[ i ][ 1 ], values[ i ] );
            graph[ equations[ i ][ 1 ] ].try_emplace( equations[ i ][ 0 ], 1 / values[ i ] );
        }

        std::vector< double > result;
        for( const auto& query : queries ) {
            std::unordered_set< std::string > visited;
            visited.insert( query[ 0 ] );
            double val = dfs( graph, visited, query[ 0 ], query[ 1 ], 1 );
            result.push_back( val );
        }

        return result;
    }

private:
    double dfs(
        const Graph& graph,
        std::unordered_set< std::string >& visited,
        const std::string& start,
        const std::string& end,
        double product 
    ) {
        if( ! graph.count( start ) || ! graph.count( end ) )
            return -1;

        if( start == end )
            return product;

        for( const auto& [adj, weight] : graph.at( start ) ) {
            if( visited.insert( adj ).second ) {
                double val = dfs( graph, visited, adj, end, product * weight );
                if( val != -1 )
                    return val;
            }
        }

        return -1;
    }
};
} //namespace

namespace {
// TODO: union-find solution
} //
