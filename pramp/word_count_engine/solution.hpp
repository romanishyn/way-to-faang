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
    vector<string> tokens;

    std::string token;
    std::stringstream ss( document );
    while( std::getline( ss, token, ' ' ) ) {
        std::string word;
        for( char c : token ) {
            if( std::isalpha( c ) )
                word += std::tolower( c );
        }

        if( !word.empty() )
            tokens.push_back( std::move( word ) );
    }

    return tokens;
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