/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using std::vector;

namespace V1 {
class Solution {
public:
    int longestConsecutive( vector< int > & nums ) {
        if( nums.size() <= 1 )
            return nums.size();

        std::sort( nums.begin(), nums.end() );

        int current = 1;
        int max = 1;

        for( int i = 1; i < nums.size(); ++i ) {
            if( nums[ i ] == nums[ i - 1 ] )
                continue;

            if( nums[ i ] == nums[ i - 1 ] + 1 )
                ++current;
            else
                current = 1;

            max = std::max( max, current );
        }

        return max;
    }
};
}

namespace V2 {
class Solution {
public:
    int longestConsecutive( vector< int > & nums ) {
        std::unordered_set< int > set( nums.begin(), nums.end() );

        int max = 0;

        for( int x : set ) {
            int curMax = 1;
            if( !set.count( x - 1 ) && set.count( x + 1 ) ) {
                int curNum = x + 1;

                while( set.count( curNum ) ) {
                    ++curNum;
                    ++curMax;
                }
            }

            max = std::max( max, curMax );
        }

        return max;
    }
};
}

namespace V3 {
class UnionFind {
public:
    explicit UnionFind( int size ) {
        m_size = m_components = size;

        m_sz.reserve( size );
        m_id.reserve( size );

        for( int i = 0; i < size; ++i ) {
            m_sz[ i ] = 1;
            m_id[ i ] = i;
        }
    }

    int find( int p ) {
        int root = p;

        while( root != m_id[ root ] )
            root = m_id[ root ];

        while( root != m_id[ p ] ) {
            int next = m_id[ p ];
            m_id[ p ] = root;
            p = next;
        }

        return root;
    }

    int findRecursion( int p ) {
        if( p == m_id[ p ] )
            return p;

        m_id[ p ] = find( m_id[ p ] );
        return m_id[ p ];
    }

    void unify( int p, int q ) {
        int root1 = find( p );
        int root2 = find( q );

        if( root1 == root2 )
            return;

        if( m_sz[ root1 ] < m_sz[ root2 ] ) {
            m_sz[ root2 ] += m_sz[ root1 ];
            m_id[ root1 ] = root2;
        }
        else {
            m_sz[ root1 ] += m_sz[ root2 ];
            m_id[ root2 ] = root1;
        }

        --m_components;
    }

    int components() {
        return m_components;
    }

    int size( int p ) {
        return m_sz[ find( p ) ];
    }

    int connected( int p, int q ) {
        return find( p ) == find( q );
    }

private:
    int m_size;
    int m_components;

    vector< int > m_sz;
    vector< int > m_id;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.empty() )
            return 0;

        std::unordered_map< int, int > map;

        const int size = nums.size();

        UnionFind unionFind( size );

        for( int i = 0; i < size; ++i ) {
            map.emplace( nums[ i ], i );
        }

        for( int x : nums ) {
            auto it = map.find( x - 1 );

            if( it != map.end() ) {
                unionFind.unify( map[ x ], it->second );
            }

            it = map.find( x + 1 );
            if( it != map.end() ) {
                unionFind.unify( map[ x ], it->second );
            }
        }

        int max = 0;
        for( int i = 0; i < size; ++i ) {
            if( max < unionFind.size( i ) )
                max = unionFind.size( i );
        }

        return max;
    }
};

} // namespace V3

namespace V4 {

class UnionFind {
public:
    explicit UnionFind( int size )
    :   m_id( size )
    ,   m_sz( size, 1 )
    {
        for( int i = 0; i < size; ++i )
            m_id[ i ] = i;
    }

    int size( int p ) {
        return m_sz[ find( p ) ];
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
        int root1 = find( p );
        int root2 = find( q );

        if( m_sz[ root1 ] < m_sz[ root2 ] ) {
            m_sz[ root2 ] += m_sz[ root1 ];
            m_id[ root1 ] = root2;
        }
        else {
            m_sz[ root1 ] += m_sz[ root2 ];
            m_id[ root2 ] = root1;
        }
    }

private:
    vector< int > m_id;
    vector< int > m_sz;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int size = nums.size();

        UnionFind unionFind( size );
        std::unordered_map< int, int > map; // <val, idx>

        for( int i = 0; i < size; ++i ) {
            if( map.count( nums[ i ] ) )
                continue;

            map[ nums[ i ] ] = i;

            auto it = map.find( nums[ i ] - 1 );
            if( it != map.end() )
                unionFind.unify( i, it->second );

            it = map.find(( nums[ i ] + 1 ) );
            if( it != map.end() )
                unionFind.unify( i, it->second );
        }

        int max = 0;
        for( int i = 0; i < size; ++i ) {
            max = std::max( max, unionFind.size( i ) );
        }

        return max;
    }
};

} // namespace V4

namespace V5 {

class UnionFind {
public:
    explicit UnionFind( int size )
        :   m_id( size )
    {
        for( int i = 0; i < size; ++i )
            m_id[ i ] = i;
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
        int root1 = find( p );
        int root2 = find( q );

        m_id[ root1 ] = root2;
    }

    int getMaxComponent() {
        vector< int > counter( m_id.size(), 0 );

        int max = 0;
        for( int i = 0; i < m_id.size(); ++i ) {
            ++counter[ find( i ) ];
            max = std::max( max, counter[ find( i ) ] );
        }

        return max;
    }

private:
    vector< int > m_id;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int size = nums.size();

        UnionFind unionFind( size );
        std::unordered_map< int, int > map; // <val, idx>

        for( int i = 0; i < size; ++i ) {
            if( map.count( nums[ i ] ) )
                continue;

            map[ nums[ i ] ] = i;

            auto it = map.find( nums[ i ] - 1 );
            if( it != map.end() )
                unionFind.unify( i, it->second );

            it = map.find(( nums[ i ] + 1 ) );
            if( it != map.end() )
                unionFind.unify( i, it->second );
        }

        return unionFind.getMaxComponent();
    }
};
} // namespace V5