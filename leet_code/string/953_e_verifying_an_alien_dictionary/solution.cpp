/*
https://leetcode.com/problems/verifying-an-alien-dictionary/

 In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

 Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

*/

#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <array>

using std::vector;
using std::string;

namespace V1 {
/*
 * We are gonna compare string by string, and if they don't satisfy condition return false, after comparing all strings return true.
 * To compare string we need convert order in alphabet (in might be array or unordered_map) where key is character,
 * value is index of character in order. Also we create helper function compare, which will use alpabet and compare character by character.
 * Function might return value like: less zero if left string is less, zero if strings are equal, and greater than zero if right string is greater.
 *
 * N - number of words
 * K - length of the longer string
 *
 * Time (N*K), since in the worst case we need to compare all strings, if words are sorted
 * Space (1), since alphabet won't be greater than 26
 * */
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        const auto alphabet = createAlphabet( order );

        for( int i = 1; i < words.size(); ++i ) {
            if( compare( words[ i - 1 ], words[ i ], alphabet ) > 0 )
                return false;
        }

        return true;
    }

private:
    using Alphabet = std::array< char, 26 >;

private:
    Alphabet createAlphabet( std::string_view order ) {
        Alphabet alphabet;
        for( int i = 0; i < order.size(); ++i )
            alphabet[ order[ i ] - 'a' ] = i;
        return alphabet;
    }

    int compare( std::string_view str1, std::string_view str2, const Alphabet & alphabet ) {
        while( !str1.empty() && !str2.empty() ) {
            if( str1.front() != str2.front() ) {
                return alphabet[ str1.front() - 'a' ] - alphabet[ str2.front() - 'a' ];
            }

            str1.remove_prefix( 1 );
            str2.remove_prefix( 1 );
        }

        return static_cast<int >( str1.size() ) - static_cast<int >( str2.size() );
    }
};
} // namespace V1
