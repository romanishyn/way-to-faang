/*
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <array>

using std::string;

namespace V1 {
/*
 * */
class Trie {
private:
    struct Node {
        using UPtr = std::unique_ptr< Node >;

        std::unordered_map< char, UPtr > m_children;
        bool m_endOfWord;
    };

private:
    Node::UPtr m_root;

public:
    /** Initialize your data structure here. */
    Trie()
    : m_root( std::make_unique< Node >() )
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto currentNode = m_root.get();

        for( char c : word ) {
            if( currentNode->m_children.count( c ) == 0 )
                currentNode->m_children[ c ] = std::make_unique< Node >();

            currentNode = currentNode->m_children[ c ].get();
        }

        currentNode->m_endOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = searchNode( word );
        return node ? node->m_endOfWord : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchNode( prefix );
    }

private:
    Node* searchNode( const std::string& word ) {
        auto currentNode = m_root.get();

        for( char c : word ) {
            if( currentNode->m_children.count( c ) == 0 )
                return nullptr;

            currentNode = currentNode->m_children[ c ].get();
        }

        return currentNode;
    }
};
} // namespace V1

namespace V2 {
/*
 * */
class Trie {
private:
    struct Node {
        using UPtr = std::unique_ptr< Node >;

        std::array< UPtr, 26 > m_children;
        bool m_endOfWord{ false };
    };

private:
    Node::UPtr m_root;

public:
    /** Initialize your data structure here. */
    Trie()
    : m_root{ std::make_unique< Node >() }
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto currentNode = m_root.get();

        for( char c : word ) {
            c -= 'a';

            if( currentNode->m_children[ c ] == nullptr )
                currentNode->m_children[ c ] = std::make_unique< Node >();

            currentNode = currentNode->m_children[ c ].get();
        }

        currentNode->m_endOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = searchNode( word );
        return node ? node->m_endOfWord : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchNode( prefix );
    }

private:
    Node* searchNode( const std::string & word ) const {
        auto currentNode = m_root.get();

        for( char c : word ) {
            c -= 'a';

            auto node = currentNode->m_children[ c ].get();
            if( !node )
                return nullptr;

            currentNode = node;
        }

        return currentNode;
    }
};
} // namespace V2

