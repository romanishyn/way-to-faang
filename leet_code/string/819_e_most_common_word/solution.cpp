/*
https://leetcode.com/problems/most-common-word/
*/

#include <string>

using std::stirng;

namespace {
/*
N - size of paragraph
M - size of banned

Time O(N+M)
Space O(N+M)
*/
class Solution {
    class WordIterator {
        private:
            std::string_view str;
            int idx{ 0 };

        private:
            void goToNextAlpha() {
                while( isValid() && ! std::isalpha( str[ idx ] ) ) {
                    ++idx;
                }
            }

        public:
            WordIterator( std::string_view str )
            :   str{ str }
            {
                goToNextAlpha();
            }

            bool isValid() const {
                return idx < str.size();
            }

            std::string next() {
                std::string result;
                while( isValid() && std::isalpha( str[ idx ] ) ) {
                    result += std::tolower( str[ idx ] );
                    ++idx;
                }
                goToNextAlpha();
                return result;
            }
    };
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        const std::unordered_set< std::string > bannedWords( begin( banned ), end( banned ) );

        std::unordered_map< std::string, int > wordFrequency;
        WordIterator iterator{ paragraph };
        int maxFrequency = -1;
        while( iterator.isValid() ) {
            auto word =  iterator.next();
            if( ! bannedWords.count( word ) )
                maxFrequency = std::max( maxFrequency, ++wordFrequency[ std::move( word ) ] );
        }

        for( const auto& [ word, freq ] : wordFrequency ) {
            if( freq == maxFrequency )
                return word;
        }

        return {};
    }
};
} // namespace
