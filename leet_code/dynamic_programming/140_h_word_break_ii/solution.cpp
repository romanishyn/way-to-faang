/*
https://leetcode.com/problems/word-break-ii/
*/

#include <string>
#include <vector>
#include <unorderd_map>

using std::string;
using std::vector;

namespace {
/*
Brute Force, TLE

S - size of s
D - total size of each string in wordDict
N - size of wordDict

Time O((S^N)*S)
Space O()
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector< std::string > result;

        for( const auto& word : wordDict ) {
            if( word == s.substr( 0, word.size() ) ) {
                if( word.size() == s.size() ) {
                    result.push_back( word );
                }
                else {
                    auto subResult = wordBreak( s.substr( word.size() ), wordDict );
                    for( const auto& w : subResult ) {
                        result.push_back( word + " " + w );
                    }
                }
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*

*/
class Solution {
    using Memo = std::unordered_map< std::string, std::vector< std::string > >;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Memo memo;
        return wordBreak( memo, s, wordDict );
    }

private:
    std::vector< std::string > wordBreak(
        Memo& memo,
        const std::string& str,
        const std::vector< std::string >& wordDict )
    {
        if( auto it = memo.find( str ); it != memo.end() ) {
            return it->second;
        }

        std::vector< std::string > result;

        for( const auto& word: wordDict ) {
            if( word == str.substr( 0, word.size() ) ) {
                if( word.size() == str.size() )
                    result.push_back( word );
                else {
                    auto subResult = wordBreak( memo, str.substr( word.size() ), wordDict );
                    for( const auto& w: subResult ) {
                        result.push_back( word + " " + w );
                    }
                }
            }
        }

        return memo[ str ] = result;
    }
};
} // namespace


namespace {
/*
S - s.size
N - dict.size
D - total size of each word in dict

Time (S^N)*D - ?
Space (S) - ?
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::unordered_map< int, std::vector< std::string > > memo;
        return func( s, wordDict, 0, memo );
    }
    
private:
    std::vector< std::string > func( const std::string& s, const vector<string>& wordDict, int idx,
                                   std::unordered_map< int, std::vector< std::string > >& memo ) {
        if( memo.count( idx ) )
            return memo[ idx ];

        std::vector< std::string > result;

        for( const auto& word : wordDict ) {
            if( ( s.size() - idx ) >= word.size() && s.substr( idx, word.size() ) == word ) {
                if( ( s.size() - idx ) == word.size() )
                    result.push_back( word );
                else {
                    for( const auto& temp : func( s, wordDict, idx + word.size(), memo ) ) {
                        result.push_back( word + " " + temp );
                    }
                }
            }
        }
        
        return memo[ idx ] = result;
    }
};
} // namespace