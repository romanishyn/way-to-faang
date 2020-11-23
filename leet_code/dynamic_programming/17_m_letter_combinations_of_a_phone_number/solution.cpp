/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
class Solution {
    std::unordered_map< char, std::string > digitToLetters {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

public:
    vector<string> letterCombinations(string digits) {
        if( digits.empty() )
            return {};

        std::vector< std::string > result;
        std::string path;
        letterCombinations( result, digits, 0, path );
        return result;
    }

private:
    void letterCombinations(
        std::vector< std::string >& result,
        const std::string& digits,
        int currIdx,
        std::string& path
    ) {
        if( digits.size() == currIdx ) {
            result.push_back( path );
            return;
        }

        for( char letter : digitToLetters[ digits[ currIdx ] ] ) {
            path.push_back( letter );
            letterCombinations( result, digits, currIdx + 1, path );
            path.pop_back();
        }
    }
};
} // namespace

namespace {
class Solution {
    std::unordered_map< char, std::string > digitToLetters {
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" }
    };

public:
    vector<string> letterCombinations(string digits) {
        if( digits.empty() )
            return {};

        std::vector< std::string > result{ "" };
        for( char digit : digits ) {
            std::vector< std::string > temp;
            for( const auto& path : result ) {
                for( char letter : digitToLetters[ digit ] ) {
                    temp.push_back( path + letter );
                }
            }
            result = std::move( temp );
        }

        return result;
    }
};
} // namespace