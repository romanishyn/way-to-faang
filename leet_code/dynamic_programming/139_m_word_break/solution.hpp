/*
https://leetcode.com/problems/word-break/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <string.h>
#include <algorithm>

using std::string;
using std::vector;

//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        const std::unordered_set< std::string > set( wordDict.begin(), wordDict.end() );
//
//        return impl( s, set );
//    }
//
//    bool impl( const std::string& s, const std::unordered_set< std::string > & set ) {
//        if( s.empty() )
//            return true;
//
//        for( int i = 1; i <= s.size(); ++i ) {
//            if(
//                    set.count( s.substr( 0, i ) )
//                &&  impl( s.substr( i, s.size() - i ), set )
//            )
//            {
//                return true;
//            }
//        }
//
//        return false;
//    }
//};

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp( s.size() + 1 );
        dp[ 0 ] = true;

        for( int i = 1; i <= s.size(); ++i ) {
            for( const auto& w: wordDict ) {
                if( ( w.size() <= i ) && dp[ i - w.size() ] && ( s.substr( i - w.size(), w.size() ) == w ) ) {
                    dp[ i ] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};
