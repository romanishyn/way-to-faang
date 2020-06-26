#pragma once

#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>
#include <algorithm>

using Graph = std::vector< std::vector< int > >;
using Vector = std::vector< int >;
using Set = std::unordered_set< int >;

 // DFS
void sortImpl( int _v, Vector & _vector, Set& _visited, const Graph& _graph ) {
    _visited.insert( _v );

    for( int adj : _graph[ _v ] ){
        if( _visited.count( adj ) )
            continue;

        sortImpl( adj, _vector, _visited, _graph );
    }

    _vector.push_back( _v );
}

Vector sortDfs( const Graph& _graph ) {
    Set visited;
    Vector vector;

    for( int v = 0; v < _graph.size(); ++v ) {
        if( !visited.count( v ) )
            sortImpl( v, vector, visited, _graph );
    }

    std::reverse( vector.begin(), vector.end() );
    return vector;
}



 // BFS
std::vector< int > sortBfs( const Graph& _graph ) {
    std::vector< int > inDegree( _graph.size() );
    for( const auto& list: _graph ) {
        for( int v : list ) {
            ++inDegree[ v ];
        }
    }

    std::queue< int > queue;
    for( int i = 0; i < inDegree.size(); ++i ) {
        if( inDegree[ i ] == 0 )
            queue.push( i );
    }

    std::vector< int > result;
    while( !queue.empty() ) {
        const int v = queue.front();
        queue.pop();
        result.push_back( v );

        for( int adj : _graph[ v ] ) {
            if( --inDegree[ adj ] == 0 )
                queue.push( adj );
        }
    }

    return result;
}

/*
int main()
{
    Graph graph{
            { 2 }
        ,   { 2, 3 }
        ,   { 4 }
        ,   { 5 }
        ,   { 5 }
        ,   { 6 }
        ,   {}
    };

    Vector vector = sortDfs( graph );

    for( int v : vector )
        std::cout << v << ", ";
    std::cout << std::endl;

    vector = sortBfs( graph );
    for( int v : vector )
        std::cout << v << ", ";
    std::cout << std::endl;
}
*/
