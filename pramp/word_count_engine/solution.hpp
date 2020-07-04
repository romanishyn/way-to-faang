#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>

using namespace std;

namespace V1 {
/*
 *
 * */
vector<string> split( const std::string& document ) {
    vector<string> words;

    std::istringstream iss( document );
    for( std::string token; std::getline( iss, token, ' ' ); ) {
        std::string word;
        for( char c : token ) {
            if( std::isalpha( c ) )
                word += std::tolower( c );
        }

        if( !word.empty() )
            words.push_back( std::move( word ) );
    }

    return words;
}

vector<vector<string>> wordCountEngine( const string& document )
{
    const auto words = split( document );

    std::unordered_map< std::string, int > wordsCount;
    std::vector< std::string > uniqueWords;

    for( int i = 0; i < words.size(); ++i ) {
        auto pair = wordsCount.emplace( words[ i ], 0 );
        if( pair.second ) {
            uniqueWords.push_back( words[ i ] );
        }
        ++pair.first->second;
    }

    // Sorting a [word, occurrences] pairs by a number of words' occurrences in descending order
    std::map< int, std::vector< std::string >, std::greater<int> > wordRanks;
    for( const auto& word : uniqueWords ) {
        int rank = wordsCount[ word ];
        wordRanks[ rank ].push_back( word );
    }

    vector< vector< std::string > > result;
    for( auto& pair : wordRanks ) {
        for( auto & word : pair.second )
            result.push_back( { std::move( word ), std::to_string( pair.first ) } );
    }

    return result;
}
} // namespace V1


namespace V2 {
class Parser {
public:
    explicit Parser( std::string document )
    : m_document{ std::move( document ) }
    {
        moveToNextWord();
    }

    bool canParse() const {
        return m_idx < m_document.size();
    }

    std::string nextWord() {
        std::string word;

        while( canParse() ) {
            const char c = m_document[ m_idx++ ];

            if( std::isalpha( c ) ) {
                word += std::tolower( c );
            }
            else if ( std::isspace( c ) ) {
                moveToNextWord();
                break;
            }
        }

        return word;
    }

private:
    // dropNotAlpha
    void moveToNextWord() {
        while( canParse() && !std::isalpha( m_document[ m_idx ] ) )
            ++m_idx;
    }

private:
    std::size_t m_idx{ 0 };
    std::string m_document;
};

vector<vector<string>> wordCountEngine( const string& document )
{
    Parser parser( document );

    std::unordered_map< std::string, int > wordOccurrences;
    std::vector< std::string > words;

    int maxOccurrence = 0; // larger occurrence

    while( parser.canParse() ) {
        auto word = parser.nextWord();
        auto it = wordOccurrences.emplace( word, 0 );
        if( it.second ) {
            words.push_back( word );
        }

        int& count = it.first->second;
        ++count;

        maxOccurrence = std::max( maxOccurrence, count );
    }

    std::vector< std::vector< std::string > > sortVector( maxOccurrence + 1 );
    for( const auto& word : words ) {
        sortVector[ wordOccurrences[ word ] ].push_back( word );
    }

    vector<vector<string>> result;

    for( int i = sortVector.size() - 1; i >= 0; --i ) {
        for( const auto& word : sortVector[ i ] ) {
            result.push_back( { word, std::to_string( wordOccurrences[ word ] ) } );
        }
    }

    return result;
}
} // namespace V2