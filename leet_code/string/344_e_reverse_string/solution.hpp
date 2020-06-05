/*
https://leetcode.com/problems/reverse-string/
*/

#pragma once

#include <vector>
#include <algorithm>


using std::vector;

namespace V1 {
class Solution {
public:
    void reverseString(vector<char>& s) {
        for( int i = 0, j = s.size() - 1; i < j; ++i, --j )
            std::swap( s[ i ], s[ j ] );
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    void reverseString(vector<char>& s) {
        helper( s, 0, s.size() - 1 );
    }

private:
    void helper( vector<char>& s, int left, int right ) {
        if( left >= right )
            return;

        std::swap( s[ left ], s[ right ] );

        helper( s, left + 1, right - 1 );
    }
};
}

namespace V3 {
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while( left < right ) {
            std::swap( s[ left++ ], s[ right++ ] );
        }
    }
};
}
