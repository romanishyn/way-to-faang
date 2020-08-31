/*
https://leetcode.com/problems/largest-component-size-by-common-factor/
*/

#include <vector>

using std::vector;

namespace {
/*
Union Find + factor factorisation

M - max number
N - number of elements

Time O(N*logM*lg*N - ?
*/

class UnionFind {
    int m_components;
    std::vector< int > m_id;
    std::vector< int > m_size;

public:
    UnionFind( int size )
    :   m_components{ size }
     {
         m_id.resize( size );
         m_size.resize( size );

         for( int i = 0; i < size; ++i ) {
             m_id[ i ] = i;
             m_size[ i ] = 1;
         }
     }

     int find( int p ) {
         int root = p;
         while( root != m_id[ root ] ) {
             root = m_id[ root ];
         }

         while( p != root ) {
             int next = m_id[ p ];
             m_id[ p ] = root;
             p = next;
         }

         return root;
     }

    int size( int p ) {
        return m_size[ find( p ) ];
    }

     void unify( int p, int q ) {
         int rootP = find( p );
         int rootQ = find( q );

         if( rootP == rootQ )
             return;

         if( size( rootP ) < size( rootQ ) ) {
             m_size[ rootQ ] += m_size[ rootP ];
             m_id[ rootP ] = rootQ;
         }
         else {
             m_size[ rootP ] += m_size[ rootQ ];
             m_id[ rootQ ] = rootP;
         }

         --m_components;
     }

     int getMaxComponentSize() {
         auto maxIt = std::max_element( m_size.begin(), m_size.end() );
         return *maxIt;
     }
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        const int size = A.size();

        std::unordered_map< int, int > factorToNumIdx;
        UnionFind unionFind( size );

        for( int i = 0; i < size; ++i ) {
            for( int factor = 2; factor * factor <= A[ i ]; ++factor ) {
                if( A[ i ] % factor == 0 ) {
                    addOrGroup( factorToNumIdx, unionFind, factor, i );
                    addOrGroup( factorToNumIdx, unionFind, A[ i ] / factor, i );
                }
            }
            addOrGroup( factorToNumIdx, unionFind, A[ i ], i );
        }

        return unionFind.getMaxComponentSize();
    }

private:
    void addOrGroup( std::unordered_map< int, int >& factorToNumIdx, UnionFind& unionFind, int factor, int numIdx ) {
        auto [ it, ins ] = factorToNumIdx.try_emplace( factor, numIdx );
        if( !ins ) {
            unionFind.unify( numIdx, it->second );
        }
    }
};
} // namespace