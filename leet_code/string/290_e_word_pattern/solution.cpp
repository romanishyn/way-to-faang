/*
https://leetcode.com/problems/word-pattern/
*/

#include <string>
#include <unordered_map>

using std::string;

namespace {
/*
Two hash maps. Bidirectional comparison char <-> word

N - length of pattern
M - lenght of str

Time O(min(N,M))
Space O(min(N,M))
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::unordered_map< char, std::string > charToWord;
        std::unordered_map< std::string, char > wordToChar;

        std::string_view patternView{ pattern };
        std::string word;
        std::istringstream iss{ str };

        while( iss >> word ) {
            if( patternView.empty() )
                return false;

            char ch = patternView.front();
            patternView.remove_prefix( 1 );

            auto [chIt, chIns] = charToWord.try_emplace( ch, word );
            auto [wordIt, wordIns] = wordToChar.try_emplace( word, ch );

            if( chIns != wordIns || chIt->first != wordIt->second )
                return false;
        }

        return patternView.empty();
    }
};
} // namespace

namespace {
/*
Two hashmaps. Mapping between value and index of first appearance.

N - length of pattern
M - lenght of str

Time O(min(N,M))
Space O(min(N,M))
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        std::unordered_map< char, int > chars;
        std::unordered_map< std::string, int > words;

        int idx = 0;
        std::string word;
        std::istringstream iss{ str };
        for(  ;iss >> word; ++idx ) {
            if( idx == pattern.size() )
                return false;

            auto [charIt, charIns] = chars.try_emplace( pattern[ idx ], idx );
            auto [wordIt, wordIds] = words.try_emplace( word, idx );

            if( charIt->second != wordIt->second )
                return false;
        }

        return idx == pattern.size();
    }
};
} // namespace
