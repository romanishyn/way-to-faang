/*
https://leetcode.com/problems/word-search-ii/
*/

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <array>
#include <vector>

using std::string;
using std::vector;

/*
[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
["oath","pea","eat","rain"]
*/
namespace V1 {
/* Using backtracking and Trie structure we can solve this problem, backtracking will explore board using BFS, to avoid
 * visiting the same call more than once, we will change current of board to "*" and after DFS recover.
 *
 * 1) Create and fill trie. Each node of structure is node and trie, it provide us posibility to consider each subtree like independent tree.
 *    When we find current work we should push this word to the result and continue searching word, because prefixes might be the same.
 *
 * ...
 *
 * Time (3^K), where K is the longest length of words
 * Space ?? how to calculate space for Trie?
 * */
class Solution {
public:
    vector< string > findWords( vector< vector< char>> & board, vector< string > & words ) {
        vector< string > result;

        auto root = buildTree( words );

        for( int i = 0; i < board.size(); ++i ) {
            for( int j = 0; j < board[ 0 ].size(); ++j )
                findWords( board, result, *root, i, j );
        }

        return result;
    }

private:
    class TrieNode {
    public:
        using UPtr = std::unique_ptr< TrieNode >;

        std::unordered_map< char, UPtr > m_children;
        std::string m_word;
    };

    void findWords( vector< vector< char >> & board, vector< std::string > & result, TrieNode & node, int x, int y ) {
        if( x < 0 || x >= board.size() || y < 0 || y >= board[ 0 ].size() )
            return;
        if( board[ x ][ y ] == '*' )
            return;

        auto it = node.m_children.find( board[ x ][ y ] );
        if( it == node.m_children.end() )
            return;

        auto& nextNode = *it->second;

        if( !nextNode.m_word.empty() )
            result.push_back( std::move( nextNode.m_word ) );

        const char temp = board[ x ][ y ];
        board[ x ][ y ] = '*';

        findWords( board, result, nextNode, x + 1, y );
        findWords( board, result, nextNode, x - 1, y );
        findWords( board, result, nextNode, x, y + 1 );
        findWords( board, result, nextNode, x, y - 1 );

        board[ x ][ y ] = temp;
    }

    TrieNode::UPtr buildTree( vector< std::string > & words ) {
        auto root = std::make_unique< TrieNode >();

        for( auto & word : words ) {
            auto currentNode = root.get();

            for( char c : word ) {
                if( currentNode->m_children.count( c ) == 0 )
                    currentNode->m_children[ c ] = std::make_unique< TrieNode >();

                currentNode = currentNode->m_children[ c ].get();
            }

            currentNode->m_word = std::move( word );
        }

        return root;
    }
};
} // namespace V1

