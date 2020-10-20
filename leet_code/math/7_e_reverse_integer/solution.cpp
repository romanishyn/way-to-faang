/*
https://leetcode.com/problems/reverse-integer/
*/

#include <limits>

namespace {
class Solution {
public:
    int reverse(int x) {
        int result = 0;

        constexpr int maxInt = std::numeric_limits< int >::max();
        constexpr int minInt = std::numeric_limits< int >::min();

        while( x ) {
            const int digit = x % 10;
            x /= 10;

            if( ( maxInt / 10 < result ) || ( maxInt / 10 == result && digit > 7 ) )
                return 0;
            if( ( minInt / 10 > result ) || ( minInt / 10 == result && digit < -8 ) )
                return 0;

            result *= 10;
            result += digit;
        }

        return result;
    }
};
} // namespace
