#pragma once

#include <unordered_map>
#include <memory>
#include <string>

// Based on: std::unordered_map + std::unique_ptr
namespace V1 {
class Trie {
private:
    class Node {
    public:
        using Ptr = std::unique_ptr< Node >;

        std::unordered_map< char, Node::Ptr > m_children;
        bool m_endOfWord{ false };
    };

private:
    Node::Ptr m_root;

public:
    Trie()
    : m_root{ std::make_unique< Node >() }
    {}

    void insert( const std::string& string ) {
        auto currentNode = m_root.get();
        for( char x : string ) {
            if( currentNode->m_children.count( x ) == 0 ) {
                currentNode->m_children[ x ] = std::make_unique< Node >();
            }

            currentNode = currentNode->m_children[ x ].get();
        }

        currentNode->m_endOfWord = true;
    }

    void insertRecursive( const std::string& string ) {
        insertRecursive( m_root.get(), string, 0 );
    }

    void insertRecursive( Node* node, const std::string& string, int idx ) {
        if( idx == string.size() ) {
            node->m_endOfWord = true;
            return;
        }

        if( node->m_children.count( string[ idx ] ) == 0 ) {
            node->m_children[ string[ idx ] ] = std::make_unique< Node >();
        }

        insertRecursive( node->m_children[ string[ idx ] ].get(), string, idx + 1 );
    }

    bool search( const std::string& string ) const {
        auto currentNode = m_root.get();

        for( char x : string ) {
            auto it = currentNode->m_children.find( x );
            if( it == currentNode->m_children.end() )
                return false;

            currentNode = it->second.get();
        }

        return currentNode->m_endOfWord;
    }

    bool searchRecursive( const std::string& string ) const {
        return searchRecursive( m_root.get(), string, 0 );
    }

    bool searchRecursive( const Node* node, const std::string& string, int idx ) const {
        if( idx == string.size() )
            return node->m_endOfWord;

        auto it = node->m_children.find( string[ idx ] );
        if( it == node->m_children.end() )
            return false;

        return searchRecursive( it->second.get(), string, idx + 1 );
    }

    void remove( const std::string& string ) {
        remove( m_root.get(), string, 0 );
    }

    bool remove( Node* node, const std::string& string, int idx ) {
        if( idx == string.size() ) {
            if( !node->m_endOfWord )
                return false;

            node->m_endOfWord = false;

            return node->m_children.size() == 0;
        }

        auto it = node->m_children.find( string[ idx ] );
        if( it == node->m_children.end() )
            return false;

        const bool shouldRemoveNode = remove( it->second.get(), string, idx + 1 );

        if( shouldRemoveNode ) {
            node->m_children.erase( it );

            return node->m_children.size() == 0 && !node->m_endOfWord;
        }

        return false;
    }

    bool isEmpty() const {
        std::cout << "children: " << m_root->m_children.size() << std::endl;
        std::cout << "m_end of word: " << m_root->m_endOfWord << std::endl;
        return m_root->m_children.empty();
    }
};

/*
 *
    {
        V1::Trie trie;

        trie.insert( "hello" );
        assert( trie.search( "hello" ) );

        trie.insert( "helloworld" );
        assert( trie.search( "helloworld" ) );

//    new int;

        assert( !trie.search( "helll" ) );

        trie.insert( "hell" );
        assert( trie.search( "hell" ) );

        trie.insert( "h" );
        assert( trie.search( "h" ) );

        trie.remove( "hello" );
        assert( !trie.search( "hello" ) );

        assert( trie.search( "hell" ) );
        assert( trie.search( "helloworld" ) );

        trie.remove( "h" );
        assert( !trie.search( "h" ) );
        assert( trie.search( "hell" ) );
        assert( trie.search( "helloworld" ) );

        trie.remove( "helloworld" );
        assert( !trie.search( "helloworld" ) );
        assert( !trie.isEmpty() );
        assert( trie.search( "hell" ) );

        trie.remove( "hell" );
        assert( trie.isEmpty() );
        assert( !trie.search( "hell" ) );
    }

    {
        V1::Trie trie;

        trie.insertRecursive( "hello" );
        assert( trie.searchRecursive( "hello" ) );

        trie.insertRecursive( "helloworld" );
        assert( trie.searchRecursive( "helloworld" ) );

//    new int;

        assert( !trie.searchRecursive( "helll" ) );

        trie.insertRecursive( "hell" );
        assert( trie.searchRecursive( "hell" ) );

        trie.insertRecursive( "h" );
        assert( trie.searchRecursive( "h" ) );

        trie.remove( "hello" );
        assert( !trie.searchRecursive( "hello" ) );

        assert( trie.searchRecursive( "hell" ) );
        assert( trie.searchRecursive( "helloworld" ) );

        trie.remove( "h" );
        assert( !trie.searchRecursive( "h" ) );
        assert( trie.searchRecursive( "hell" ) );
        assert( trie.searchRecursive( "helloworld" ) );

        trie.remove( "helloworld" );
        assert( !trie.searchRecursive( "helloworld" ) );
        assert( !trie.isEmpty() );
        assert( trie.searchRecursive( "hell" ) );

        trie.remove( "hell" );
        assert( trie.isEmpty() );
        assert( !trie.searchRecursive( "hell" ) );
    }
 *
 */
} // namespace V1