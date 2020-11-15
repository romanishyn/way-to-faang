/*
https://leetcode.com/problems/friend-circles/
*/

#include <vector>

using std::vector;

namespace {
/*
Disjoint-set data structure

N - M.size

Time O(N^2)
Space O(N)
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int N = M.size();

        DisjointSet disjointSet( N );

        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < N; ++j ) {
                if( M[ i ][ j ] == 1 ) {
                    disjointSet.unify( i, j );
                }
            }
        }

        return disjointSet.getComponents();
    }

private:
    class DisjointSet {
        std::vector< int > ids;
        std::vector< int > sizes;
        int components;

    public:
        DisjointSet( int size )
        :   ids( size )
        ,   sizes( size, 1 )
        ,   components( size )
        {
            for( int i = 0; i < size; ++i )
                ids[ i ] = i;
        }

        int find( int p ) {
            int root = p;
            while( root != ids[ root ] )
                root = ids[ root ];

            while( root != p ) {
                int next = ids[ p ];
                ids[ p ] = root;
                p = next;
            }

            return root;
        }

        void unify( int p, int q ) {
            const int rootP = find( p );
            const int rootQ = find( q );

            if( rootP == rootQ )
                return;

            if( sizes[ rootP ] < sizes[ rootQ ] ) {
                sizes[ rootQ ] += sizes[ rootP ];
                ids[ rootP ] = rootQ;
            }
            else {
                sizes[ rootP ] += sizes[ rootQ ];
                ids[ rootQ ] = rootP;
            }

            --components;
        }

        int getComponents() {
            return components;
        }
    }; // class DisjointSet
};
} // namespace

namespace {
/*
DFS

N - M.size

Time O(N^2)
Space O(N)
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int N = M.size();

        int components = 0;
        std::unordered_set< int > seen;
        for( int i = 0; i < N; ++i ) {
            if( ! seen.insert( i ).second )
                continue;

            std::stack< int > stack;
            stack.push( i );

            while( ! stack.empty() ) {
                auto vertex = stack.top();
                stack.pop();

                for( int j = 0; j < N; ++j ) {
                    if( M[ vertex ][ j ] == 1 && seen.insert( j ).second )
                        stack.push( j );
                }
            }

            ++components;
        }

        return components;
    }
};
} // namespace
