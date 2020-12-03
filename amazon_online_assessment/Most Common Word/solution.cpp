/*
https://leetcode.com/problems/most-common-word/
*/

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace {
/*
N - number of characters in input string
M - number of characters in the banned list

Time O(N+M)
Space O(N+M)
*/
class Solution {
    class TextIterator {
    private:
        const std::string text;
        int idx = 0;

        void goToNextLetter() {
            while( isValid() && ! std::isalpha( text[ idx ] ) )
                ++idx;
        }

    public:
        TextIterator( std::string text )
        :   text{ std::move( text ) }
        {
            goToNextLetter();
        }

        bool isValid() {
            return idx < text.size();
        }

        std::string next() {
            std::string word;
            while( isValid() && std::isalpha( text[ idx ] ) ) {
                word += text[ idx ];
                ++idx;
            }
            goToNextLetter();
            return word;
        }
    };

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::unordered_set< std::string > bannedWords( begin( banned ), end( banned ) );
        std::unordered_map< std::string, int > wordToFreq;
        TextIterator iterator{ paragraph };
        int maxFreq = 0;

        while( iterator.isValid() ) {
            auto word = iterator.next();
            for( char& ch : word )
                ch = std::tolower( ch );

            if( ! bannedWords.count( word ) ) {
                int freq = ++wordToFreq[ std::move( word ) ];
                maxFreq = std::max( maxFreq, freq );
            }
        }

        for( const auto& [word, freq] : wordToFreq ) {
            if( freq == maxFreq )
                return word;
        }

        return "";
    }
};
} // namespace
