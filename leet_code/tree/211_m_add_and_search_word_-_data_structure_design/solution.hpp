/*
https://leetcode.com/problems/add-and-search-word-data-structure-design/
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <array>

using std::string;

namespace V1 {
/*
 * Using backtracking and trie to check each character of word. The main difficulty is to deal with '.'. To solve this
 * problem, we will use naive solution: each time when we encounter a '.', simply check all the children of the current node
 * and recursively search the remaining substring starting from each of those children
 *
 * ?? Time (26^n), n - number of characters in alphabet
 * ?? Space (26^n), n - number of characters in alphabet
 * */
class WordDictionary {
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
    WordDictionary()
        : m_root( std::make_unique< Node >() )
    {
    }

    /** Adds a word into the data structure. */
    void addWord( string word ) {
        auto currentNode = m_root.get();

        for( char c : word ) {
            if( currentNode->m_children.count( c ) == 0 )
                currentNode->m_children[ c ] = std::make_unique< Node >();

            currentNode = currentNode->m_children[ c ].get();
        }

        currentNode->m_endOfWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search( string word ) {
        return search( m_root.get(), word, 0 );
    }

private:
    bool search( const Node* node, const std::string& word, int idx ) const {
        if( word.size() == idx )
            return node->m_endOfWord;

        if( word[ idx ] == '.' ) {
            for( const auto& [ c, child ] : node->m_children ) {
                if( search( child.get(), word, idx + 1 ) )
                    return true;
            }

            return false;
        }
        else {
            auto it = node->m_children.find( word[ idx ] );
            if( it == node->m_children.end() )
                return false;

            return search( it->second.get(), word, idx + 1 );
        }
    }
};
} // namespace V1


namespace V2 {
/*
 * Using backtracking and Trie, Node in trie is based on array of 26 elements (a-z). To solve case when we search work and
 * encounter symbol '.' we simply check each childr of current node recursively.
 *
 * Time - TBD
 * Space - TBD
 * */
class WordDictionary {
private:
    struct Node {
        using UPtr = std::unique_ptr< Node >;

        std::array< UPtr, 26 > m_children;
        bool m_endOfWord;
    };

private:
    Node::UPtr m_root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    : m_root( std::make_unique< Node >() )
    {
    }

    /** Adds a word into the data structure. */
    void addWord( string word ) {
        auto currentNode = m_root.get();

        for( char c : word ) {
            if( currentNode->m_children[ c - 'a' ] == nullptr )
                currentNode->m_children[ c - 'a' ] = std::make_unique< Node >();

            currentNode = currentNode->m_children[ c - 'a' ].get();
        }

        currentNode->m_endOfWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search( string word ) {
        return search( m_root.get(), word, 0 );
    }

private:
    bool search( const Node* node, const std::string& word, int idx ) {
        if( word.size() == idx )
            return node->m_endOfWord;

        if( word[ idx ] == '.' ) {
            for( const auto& child : node->m_children ) {
                if( child && search( child.get(), word, idx + 1 ) )
                    return true;
            }
        }
        else if( node->m_children[ word[ idx ] - 'a' ] ) {
            return search( node->m_children[ word[ idx ] - 'a' ].get(), word, idx + 1 );
        }

        return false;
    }
};
} // namespace V2