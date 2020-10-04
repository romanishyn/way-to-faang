/*
https://leetcode.com/problems/accounts-merge/
*/

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;

namespace {
/*
Based on UnionFind

Time - ?
Space - ?
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map< std::string, int > emailToIdx;
        std::unordered_map< std::string, std::string > emailToName;
        UF groups( 10000 );

        int idx = 0;
        for( const auto& account: accounts ) {
            for( int i = 1; i < account.size(); ++i ) {
                auto [it, _] = emailToIdx.try_emplace( account[ i ], idx++ );
                emailToName.try_emplace( account[ i ], account[ 0 ] );
                groups.unify( emailToIdx[ account[ 1 ] ], it->second );
            }
        }

        std::unordered_map< int, std::set< std::string > > mergeGroup;
        for( auto& [email, index] : emailToIdx ) {
            mergeGroup[ groups.find( index ) ].insert( email );
        }

        std::vector< std::vector< std::string > > result;
        for( auto& [_, group] : mergeGroup ) {
            std::vector< std::string > acc{ emailToName[ *group.begin() ] };
            std::move( group.begin(), group.end(), std::back_inserter( acc ) );
            result.push_back( std::move( acc ) );
        }

        return result;
    }

private:
    class UF {
        std::vector< int > m_sz;
        std::vector< int > m_id;
        int m_components;

    public:
        UF( int size )
        :    m_sz( size )
        ,   m_id( size )
        ,   m_components( size )
        {
            for( int i = 0; i < size; ++i ) {
                m_id[ i ] = i;
            }
        }

        int find( int p ) {
            int root = p;
            while( root != m_id[ root ] )
                root = m_id[ root ];

            while( p != root ) {
                int next = m_id[ p ];
                m_id[ p ] = root;
                p = next;
            }

            return root;
        }

        void unify( int p, int q ) {
            int rootP = find( p );
            int rootQ = find( q );

            if( rootP == rootQ )
                return;

            if( m_sz[ rootP ] > m_sz[ rootQ ] ) {
                m_sz[ rootP ] += m_sz[ rootQ ];
                m_id[ rootQ ] = rootP;
            }
            else {
                m_sz[ rootQ ] += m_sz[ rootP ];
                m_id[ rootP ] = rootQ;
            }

            --m_components;
        }

        int getComponents() {
            return m_components;
        }
    };
};
} // namespace

namespace {
/*
Based on UnionFind
Compared to previous solution, deleted emailName and UF has less size

Time - ?
Space - ?
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UF groups( accounts.size() );
        std::unordered_map< std::string, int > emailToIdx;

        for( int i = 0; i < accounts.size(); ++i ) {
            const auto& account = accounts[ i ];

            for( int j = 1; j < account.size(); ++j ) {
                emailToIdx.try_emplace( account[ j ], i );
                groups.unify( emailToIdx[ account[ 1 ] ],  emailToIdx[ account[ j ] ] );
            }
        }

        std::unordered_map< int, std::set< std::string > > sortedGroups;
        for( auto& [ email, idx ] : emailToIdx ) {
            sortedGroups[ groups.find( idx ) ].insert( email );
        }

        std::vector< std::vector< std::string > > result;
        for( auto& [ idx, group ] : sortedGroups ) {
            std::vector< std::string > account{ accounts[ idx ][ 0 ] };
            std::move( group.begin(), group.end(), std::back_inserter( account ) );
            result.push_back( std::move( account ) );
        }

        return result;
    }
    
private:
    class UF {
        std::vector< int > m_id;
        std::vector< int > m_sz;
        int m_components;

    public:
        UF( int size )
        :   m_id( size )
        ,   m_sz( size )
        ,   m_components( size )
        {
            for( int i = 0; i < size; ++i )
                m_id[ i ] = i;
        }

        int find( int p ) {
            int root = p;

            while( root != m_id[ root ] )
                root = m_id[ root ];

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
    };
};
} // namespace

namespace {
/*
Based on DFS
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::unordered_map< std::string, std::unordered_set< std::string > > graph;
        std::unordered_map< std::string, std::string > emailToName;

        for( int i = 0; i < accounts.size(); ++i ) {
            const auto& account = accounts[ i ];
            for( int j = 1; j < account.size(); ++j ) {
                emailToName.try_emplace( account[ j ], account[ 0 ] );
                graph.try_empalce( account[ j ], {} );
                if( j != 1 ) {
                    graph[ account[ j ] ].insert( account[ j - 1 ] );
                    graph[ account[ j - 1 ] ].insert( account[ j ] );
                }
            }
        }

        std::vector< std::vector< std::string > > result;

        std::unordered_set< std::string > seen;
        std::stack< std::string > todo;
        for( auto& [vertex, neighbords] : graph ) {
            if( ! seen.insert( vertex ).second )
                continue;

            std::vector< std::stirng > account{ emailToName[ vertex ] };

            todo.push( vertex );
            while( ! todo.empty() ) {
                auto node = todo.top();
                todo.pop();

                account.push_back( node );
                for( const auto& adj : graph[ node ] ) {
                    if( seen.insert( adj ).second )
                        todo.push( adj );
                }
            }

            result.push_back( account );
        }

        return result;
    }
};
} // namespace
