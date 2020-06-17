/*
https://leetcode.com/problems/valid-anagram/
*/

#pragma once

#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::vector;

namespace V1 {
/*
 * If strings have different length than mead they are different.
 * Otherwise we create array of integers to count a count of all characters in s. And then iterate over t
 * and check if current char present in array, if yes we decrease count of character, else return false, because
 * t doesn't contain this char, or this char has more appearances in t.
 *
 * Time (n)
 * Space (1)
 * */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() )
            return false;

        int set[ 26 ] = {};
        for( char c : s )
            ++set[ c - 'a' ];

        for( char c : t ) {
            if( set[ c - 'a'] )
                --set[ c - 'a' ];
            else
                return false;
        }

        return true;
    }
};
} // namespace V1

namespace V2 {
/*
 * The idea is to uses map to count appearances of characters in each string. For string s we'll increase counter,
 * for string t decrease. In the end, if those tow strings are anagrams of each other,
 * all the counters will be zero, else it's not.
 * To speed up and decrease memory consumption of our program we can use array of 26 elements, since we know than strigns contain only
 * letter from English alphabet. And make simple math with each character.
 *
 * Time (n)
 * Space (1)
 * */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() )
            return false;

        int counts[ 26 ] = {};

        for( int i = 0; i < s.size(); ++i ) {
            ++counts[ s[ i ] - 'a' ];
            --counts[ t[ i ] - 'a' ];
        }

        for( int count : counts ) {
            if( count != 0 )
                return false;
        }

        return true;
    }
};
} // namespace V2

namespace V3 {
/* If sort two anagrams in the same order, they will be equal, it they are not, that mead they are not anagrams.
 *
 * Time (nlogn)
 * Space (1)
 * */
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort( s.begin(), s.end() );
        std::sort( t.begin(), t.end() );

        return s == t;
    }
};
} // namespace V3
