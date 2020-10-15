/*
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
*/

#include <vector>

using std::vector;

namespace {
/*
V - number of vertecis
E - number of edges

Time O(E) - ?O(E * lg*V)
Space O(V)
*/
class UF {
    std::vector< int > m_id;
    std::vector< int > m_sz;
    int m_components;

public:
    UF( int size )
    :   m_id( size )
    ,   m_sz( size, 1 )
    ,   m_components( size )
    {
        for( int i = 0; i < size; ++i ) {
            m_id[ i ] = i;
        }
    }

    int find( int p ) {
        int root = p;
        while( root != m_id[ root ] ) {
            root = m_id[ root ];
        }

        while( root != p ) {
            int next = m_id[ p ];
            m_id[ p ] = root;
            p = next;
        }

        return root;
    }

    void unify( int p, int q ) {
        const int rootP = find( p );
        const int rootQ = find( q );
        
        if( rootP == rootQ )
            return;

        if( m_sz[ rootP ] < m_sz[ rootQ ] ) {
            m_sz[ rootQ ] += m_sz[ rootP ];
            m_id[ rootP ] = rootQ;
        }
        else {
            m_sz[ rootP ] += m_sz[ rootQ ];
            m_id[ rootQ ] = rootP;
        }

        --m_components;
    }

    int getComponents() {
        return m_components;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UF unionFind( n );

        for( const auto& edge : edges ) {
            unionFind.unify( edge[ 0 ], edge[ 1 ] );
        }

        return unionFind.getComponents();
    }
};
} // namespace

namespace {
/*
V - number of vertecis
E - number of edges

Time O(V + E)
Space O(V + E)
*/
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector< std::vector< int > > adjList( n );
        for( const auto& edge: edges ) {
            adjList[ edge[ 0 ] ].push_back( edge[ 1 ] );
            adjList[ edge[ 1 ] ].push_back( edge[ 0 ] );
        }

        std::vector< bool > seen( n );

        int components = 0;

        for( int i = 0; i < n; ++i ) {
            if( seen[ i ] )
                continue;

            std::stack< int > todo;
            todo.push( i );
            seen[ i ] = true;

            while( ! todo.empty() ) {
                int vertex = todo.top();
                todo.pop();

                for( int adj : adjList[ vertex ] ) {
                    if( ! seen[ adj ] ) {
                        seen[ adj ] = true;
                        todo.push( adj );
                    }
                }
            }

            ++components;
        }

        return components;
    }
};
} // namespace