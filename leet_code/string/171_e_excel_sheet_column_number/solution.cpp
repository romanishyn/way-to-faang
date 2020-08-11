/*
https://leetcode.com/problems/excel-sheet-column-number/
*/

#include <cmath>

namespace V1 {
/*
From left to right

N - length of string

Time O(N)
Space O(1)
Time 
*/
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        const int length = s.size();
        for( int i = 0; i < length; ++i ) {
            result += ( s[ i ] - 'A' + 1 ) * ( std::pow( 26, length - i - 1 ) );
        }
        return result;
    }
};
} // namespace V1

namespace V2 {
/*
Left to right

To add new digit in least-significant position, need to multiply the current value by a base of number (0x or 0b ...)
to allocate a place for this digit and add the digit to a new number.
In this manner, we can iteratively convert string representation of a number to integer representation

First zero is initial value
Example:
"239" to decimal
0 * 10 + 2 = 2
2 * 10 + 3 = 23
23 * 10 + 9 = 239

The same for our case
"XFD" X - 24, F - 6, D - 4
0 * 26 + 24 = 24
24 * 26 + 6 = 630
630 * 26 + 4 = 16228

N - length of string

Time O(N)
Space O(1)
*/
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for( char digit : s ) {
            result *= 26;
            result += digit - 'A' + 1;
        }
        return result;
    }
};
} // namespace V2
