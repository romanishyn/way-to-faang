/*
https://leetcode.com/problems/word-ladder/
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using std::string;
using std::vector;

namespace {
/*
N - size of wordList
L - length of word

Time O(N*L^2)
Space O(N)
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set< std::string > words( begin( wordList ), end( wordList ) );

        if( ! words.count( endWord ) )
            return 0;

        int level = 1;

        std::queue< std::string > todo;
        todo.push( beginWord );

        while( ! todo.empty() ) {
            const int levelSize = todo.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto word = todo.front();
                todo.pop();

                for( int i = 0; i < word.size(); ++i ) {
                    char saveChar = word[ i ];
                    for( char ch = 'a'; ch <= 'z'; ++ch ) {
                        word[ i ] = ch;
                        if( word == endWord )
                            return level + 1;
                        if( auto it = words.find( word ); it != words.end() ) {
                            todo.push( word );
                            words.erase( it );
                        }
                    }
                    word[ i ] = saveChar;
                }
            }

            ++level;
        }

        return 0;
    }
};
} // namespace

namespace {
/*
N - size of wordList
L - length of word

Time O(N*L^2)
Space O(N)
*/
class Solution {
    using WordSet = std::unordered_set< std::string >;

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        const int wordSize = beginWord.size();

        WordSet words( begin( wordList ), end( wordList ) );
        if( ! words.count( endWord ) )
            return 0;

        std::queue< std::string > todoBegin;
        WordSet seenBegin;
        todoBegin.push( beginWord );
        seenBegin.insert( beginWord );

        std::queue< std::string > todoEnd;
        WordSet seenEnd;
        todoEnd.push( endWord );
        seenEnd.insert( endWord );

        int ledder = 2;

        while( ! todoBegin.empty() && ! todoEnd.empty() ) {
            if( todoBegin.size() > todoEnd.size() ) {
                std::swap( todoBegin, todoEnd );
                std::swap( seenBegin, seenEnd );
            }

            const int levelSize = todoBegin.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto word = todoBegin.front();
                todoBegin.pop();

                for( int j = 0; j < wordSize; ++j ) {
                    const char saveChar = word[ j ];
                    for( char ch = 'a'; ch <= 'z'; ++ch ) {
                        word[ j ] = ch;

                        if( saveChar == ch )
                            continue;

                        if( seenEnd.count( word ) )
                            return ledder;

                        if( auto it = words.find( word ); it != words.end() ) {
                            words.erase( it );
                            todoBegin.push( word );
                            seenBegin.insert( word );
                        }
                    }
                    word[ j ] = saveChar;
                }
            }
            ++ledder;
        }

        return 0;
    }
};
} // namespace



