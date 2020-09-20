/*
https://leetcode.com/problems/alien-dictionary/
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using std::vector;
using std::string;

namespace {
/*

*/
class Solution {
    using CharIdx = std::unordered_map< char, int >;
    using Pairs = std::vector< std::pair< int, int > >;

public:
    string alienOrder(vector<string>& words) {
        auto charIdx = createCharIdx( words );
        Pairs pairs;
        for( int i = 0; i < words.size() - 1; ++i ) {
            const int wordSize = std::min( words[ i ].size(), words[ i + 1 ].size() );
            bool inserted = false;
            for( int j = 0; j < wordSize; ++j ) {
                if( words[ i ][ j ] != words[ i + 1 ][ j ] ) {
                    pairs.emplace_back( 
                        charIdx[ words[ i ][ j ] ],
                        charIdx[ words[ i + 1 ][ j ] ]
                    );
                    inserted = true;
                    break;
                }
            }
            if( ! inserted && words[ i ].size() > words[ i + 1 ].size() )
                return {};
        }

        std::vector< int > sortedIdx = topologicalSort( charIdx.size(), pairs );
        return toAlphabet( sortedIdx, charIdx );
    }

private:
    std::vector< int > topologicalSort( int size, const Pairs& pairs ) const {
        std::vector< std::vector< int > > graph( size );
        std::vector< int > inDegree( size );

        for( auto [ u, v ] : pairs ) {
            graph[ u ].push_back( v );
            ++inDegree[ v ];
        }

        std::vector< int > sortedIdx;
        std::queue< int > zeros;
        for( int i = 0; i < inDegree.size(); ++i ) {
            if( inDegree[ i ] == 0 ) {
                zeros.push( i );
            }
        }

        while( ! zeros.empty() ) {
            int vertex = zeros.front();
            zeros.pop();
            sortedIdx.push_back( vertex );

            for( int adj : graph[ vertex ] ) {
                if( --inDegree[ adj ] == 0 ) {
                    zeros.push( adj );
                }
            }
        }

        return sortedIdx.size() == size ? sortedIdx : std::vector<int>{};
    }

    std::string toAlphabet( const std::vector< int >& sortedIdx, const CharIdx& charIdx ) const {
        std::unordered_map< int, char > idxChar;
        for( auto [ ch, idx ] : charIdx )
            idxChar[ idx ] = ch;

        std::string result;
        for( int idx : sortedIdx )
            result.push_back( idxChar[ idx ] );

        return result;
    }

    CharIdx createCharIdx( const vector<string>& words ) {
        CharIdx charIdx;

        for( const auto& word: words ) {
            for( char ch : word ) {
                charIdx.try_emplace( ch, charIdx.size() );
            }
        }

        return charIdx;
    }
};
} // namespace

namespace {
class Solution {
public:
    string alienOrder(vector<string>& words) {
        std::unordered_map< char, int > inDegree;
        std::unordered_map< char, std::vector< char > > graph;

        // init
        for( const auto& word: words ) {
            for( char ch: word ) {
                inDegree[ ch ];
                graph[ ch ];
            }
        }

        // build
        for( int i = 1; i < words.size(); ++i ) {
            const std::string& prevWord = words[ i - 1 ];
            const std::string& currWord = words[ i ];

            const int prevSize = prevWord.size();
            const int currSize = currWord.size();

            bool foundDistinctChar = false;
            for( int i = 0; i < std::min( prevSize, currSize ); ++i ) {
                if( prevWord[ i ] != currWord[ i ] ) {
                    foundDistinctChar = true;
                    graph[ prevWord[ i ] ].push_back( currWord[ i ] );
                    ++inDegree[ currWord[ i ] ];
                    break;
                }
            }

            if( ! foundDistinctChar && prevSize > currSize )
                return {}; // imposible build dictionary
        }

        std::queue< char > zeros;
        for( auto [ ch, degree ] : inDegree ) {
            if( degree == 0 )
                zeros.push( ch );
        }

        std::string result;

        while( ! zeros.empty() ) {
            char ch = zeros.front();
            zeros.pop();
            result.push_back( ch );

            for( char adj : graph[ ch ] ) {
                if( --inDegree[ adj ] == 0 ) {
                    zeros.push( adj );
                }
            }
        }

        return ( result.size() == inDegree.size() ) ? result : "";
    }
};
} // namespace

namespace {
// TODO: Depth-First Search
} // namespace
