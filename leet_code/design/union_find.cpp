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