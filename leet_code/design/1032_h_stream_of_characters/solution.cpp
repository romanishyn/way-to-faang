/*
https://leetcode.com/problems/stream-of-characters/
*/

#include <vector>

using std::vector;

namespace {
/*
LC: Time Limit Exceeded

Idea is us ordinary Trie structue, but keep collection of pointers within the Trie;

W - max length of word
N - number of words

Time 
*/
class StreamChecker {
    struct Node {
        using UPtr = std::unique_ptr< Node >;

        std::unordered_map< char, UPtr > m_characters;
        bool m_endOfWord = false;
    };

    void insert( std::string_view word ) {
        auto node = m_root.get();

        for( char c : word ) {
            if( ! node->m_characters.count( c ) ) {
                node->m_characters.emplace( c, std::make_unique< Node >() );
            }

            node = node->m_characters[ c ].get();
        }

        node->m_endOfWord = true;
    }

private:

    Node::UPtr m_root;
    std::vector< Node* > m_nodes;

public:
    StreamChecker(vector<string>& words)
    :   m_root{ std::make_unique< Node >() }
    {
        for( const auto& word: words )
            insert( word );
    }

    bool query(char letter) {
        bool found = false;

        m_nodes.push_back( m_root.get() );
        std::vector< Node* > newNodes;
        for( int i = m_nodes.size() - 1; i >= 0; --i ) {
            auto node = m_nodes[ i ];

            auto it = node->m_characters.find( letter );
            if( it == node->m_characters.end() )
                continue;

            found |= it->second->m_endOfWord;
            if( ! it->second->m_characters.empty() ) {
                newNodes.push_back( it->second.get() );
            }
        }

        std::swap( m_nodes, newNodes );

        return found;
    }
};
} // namespace

namespace {
/*
Revers words and add to trie. Keep stream with length of max length word.

N - number of word
L - length of word

Time Init O(N*L), Query O(L)
Space Init O(N*L), Query O(1)
*/
class StreamChecker {
    struct Node {
        using UPtr = std::unique_ptr< Node >;
        std::array< UPtr, 26 > m_characters{};
        bool m_endOfWord{ false };
    };

    void insert( std::string_view word ) {
        auto node = m_root.get();

        for( char c : word ) {
            c -= 'a';

            if( ! node->m_characters[ c ] )
                node->m_characters[ c ] = std::make_unique< Node >();

            node = node->m_characters[ c ].get();
        }

        node->m_endOfWord = true;
    }

    Node::UPtr m_root;
    std::deque< char > m_stream;
    std::size_t m_maxLength{ 0 };

public:
    StreamChecker(vector<string>& words)
    :   m_root{ std::make_unique< Node >() }
    {
        for( auto word: words ) {
            std::reverse( std::begin( word ), std::end( word ) );
            insert( word );
            m_maxLength = std::max( m_maxLength, word.length() );
        }
    }

    bool query(char letter) {
        m_stream.push_front( letter );
        if( m_stream.size() > m_maxLength )
            m_stream.pop_back();

        auto node = m_root.get();
        for( char c : m_stream ) {
            c -= 'a';

            if( node->m_endOfWord )
                return true;
            if( ! node->m_characters[ c ] )
                return false;

            node = node->m_characters[ c ].get();
        }

        return node->m_endOfWord;
    }
};

} // namespace
