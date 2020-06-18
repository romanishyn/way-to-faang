/*
https://leetcode.com/problems/group-anagrams/
*/

#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

/*
 * TODO:
 * TIME (NK)
 *
 * */
namespace V1 {
/*
 * If we sort two strings they are anagrams if their sorted strings are equal.
 * Create map where key is string, represent sorted string, and value is vector of strings,
 * and each value is string from input data that when sorted, are equal to key.
 * Then iterate over map, and push back all value(vector) to result collection.
 *
 * N - length of strs
 * K - maximum length of a string in strs
 *
 * Time (NKlogK)
 * Space (NK)
 * */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map< string, vector< string > > map;
       for( int i = 0; i < strs.size(); ++i ) {
           auto str = strs[ i ];
           std::sort( str.begin(), str.end() );
           map[ str ].push_back( std::move( strs[ i ] ) );
       }

       vector< vector< string > > result;
       result.reserve( strs.size() );

       for( auto& [str, v] : map )
           result.push_back( std::move( v ) );

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * */
class Solution {
public:
};
} // namespace V2