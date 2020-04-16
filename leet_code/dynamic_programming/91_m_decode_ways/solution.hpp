/*
https://leetcode.com/problems/decode-ways/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <string.h>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    // 00111
    // 11001
    // 226
/*
    int numDecodings(string s) {
        if( s.empty() )
            return 1;

        int result = 0;

        int pref1 = std::stoi( s.substr(0, 1 ) );
        if( 1 <= pref1 && pref1 <= 9 ) {
            const std::string suffix = s.substr( 1, s.size() - 1 );
            result += numDecodings( suffix );
        }

        if( s.size() >= 2 ) {
            int pref2 = std::stoi( s.substr( 0, 2 ) );
            // 10 <= X <= 26
            if( 10 <= pref2 && pref2 <= 26 ) {
                const std::string suffix = s.substr( 2, s.size() - 2 );
                result += numDecodings( suffix );
            }
        }

        return result;
    }
*/

/*
 * dp[ i ] = dp[i - 1] + dp[ i - 2]
 *
 * 22                 6
 * [ 1, 1, 0, 0 ]
 *
 * */

    int numDecodings(string s) {
        if( s.empty() )
            return 0;

        vector<int> dp( s.size() + 1 );
        dp[ 0 ] = 1;
        dp[ 1 ] = s[ 0 ] != '0' ? 1 : 0;

        for( int i = 2; i <= s.size(); ++i ) {
            int pref1 = std::stoi( s.substr( i - 1, 1 ) );
            int pref2 = std::stoi( s.substr( i - 2, 2 ) );

            if( pref1 > 0 )
                dp[ i  ] += dp[ i - 1 ];

            // 10 <= X <= 26
            if( 10 <= pref2 && pref2 <= 26 )
                dp[ i ] += dp[ i - 2 ];
        }

        return dp.back();
    }
};
