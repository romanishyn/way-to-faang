#include <vector>

/*
 * Find O(1)
 * Union(N)
 * */
class QuickFindUF {
public:
    explicit QuickFindUF( int N ) {
        m_id.reserve( N );

        for( int i = 0; i < N; ++i )
            m_id[ i ] = i;
    }

    bool connected( int p, int q ) const {
        return m_id[ p ] == m_id[ q ];
    }

    void unify( int p, int q ) {
        int pId = m_id[ p ];
        int qId = m_id[ q ];

        for( int i = 0; i < m_id.size(); ++i ) {
            if( m_id[ i ] == pId )
                m_id[ i ] = qId;
        }
    }

private:
    std::vector< int > m_id;
};


/*
 *
 * */
class QuickUnionUF {
public:
    explicit QuickUnionUF( int N ) {
        m_id.reserve( N );

        for( int i = 0; i < N; ++i ) {
            m_id[ i ] = i;
        }
    }

    bool connected( int p, int q ) const {
        return root( p ) == root( q );
    }

    void unify( int p, int q ) {
        int pRoot = root( p );
        int qRoot = root( q );

        m_id[ pRoot ] = qRoot;
    }

private:
    int root( int p ) const {
        while( p != m_id[ p ] )
            p = m_id[ p ];

        return p;
    }
private:
    std::vector< int > m_id;
};

/*
 * Larger element in component
 * */
class UFWithFindLargest {
private:
    std::vector< int > m_id;
    std::vector< int > m_sz;
    std::vector< int > m_large;

    int m_components;

public:
    explicit UFWithFindLargest( int N )
    : m_components{ N }
    {
        m_id.reserve( N );
        m_sz.reserve( N );
        m_large.reserve( N );

        for( int i = 0; i < N; ++i ) {
            m_id[ i ] = i;
            m_sz[ i ] = 1;
            m_large[ i ] = i;
        }
    }

    int find( int i ) {
        int root = i;

        while( root != m_id[ root ] )
            root = m_id[ root ];

        while( i != root ) {
            int next = m_id[ i ];
            m_id[ i ] = root;
            i = next;
        }

        return root;
    }

    void unify( int p, int q ) {
        int pRoot = find( p );
        int qRoot = find( q );

        if( m_sz[ pRoot ] < m_sz[ qRoot ] ) {
            m_id[ pRoot ] = qRoot;
            m_sz[ qRoot ] += m_sz[ pRoot ];

            if( m_large[ pRoot ] > m_large[ qRoot ] )
                m_large[ qRoot ] = m_large[ pRoot ];
        }
        else {
            m_id[ qRoot ] = pRoot;
            m_sz[ pRoot ] += m_sz[ qRoot ];

            if( m_large[ qRoot ] > m_large[ pRoot ] )
                m_large[ pRoot ] = m_large[ qRoot ];
        }

        --m_components;
    }

    bool connected( int p, int q ) {
        return find( p ) == find( q );
    }

    int large( int i ) {
        return m_large[ find( i) ];
    }

    int components() {
        return m_components;
    }

    int size( int i ) {
        return m_sz[ find( i ) ];
    }
};