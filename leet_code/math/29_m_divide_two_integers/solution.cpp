/*
https://leetcode.com/problems/divide-two-integers/
*/

#include <limits>
#include <vector>

namespace {
/*
Approach 1: Repeated Subtraction

-21 / 5
-21 / -5
21 / 5
MIN_INT / 1
ans = MIN_INT

N - absolute value of dividend

Time O(N) - in case of N max int and divisor equals 1
Space O(1)
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == std::numeric_limits< int >::min() && divisor == -1 )
            return std::numeric_limits< int >::max();

        int sign = 2;
        if( dividend > 0 ) {
            --sign;
            dividend = -dividend;
        }
        if( divisor > 0 ) {
            --sign;
            divisor = -divisor;
        }

        int quotient = 0;
        while( dividend <= divisor ) {
            --quotient;
            dividend -= divisor;
        }

        if( sign != 1 ) {
            return -quotient;
        }
        return quotient;
    }
};
} // namespace

namespace {
/*
Approach 2: Repeated Exponential Searches

15 / 2

N - absolute value of dividend

Time O((log^2)N)
Space O(1)
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == std::numeric_limits< int >::min() && divisor == -1 )
            return std::numeric_limits< int >::max();

        const int halfOfMinInt = std::numeric_limits< int >::min() / 2;

        int negatives = 2;
        if( dividend > 0 ) {
            --negatives;
            dividend = -dividend;
        }
        if( divisor > 0 ) {
            --negatives;
            divisor = -divisor;
        }

        int quotient = 0;

        while( dividend <= divisor ) {
            int value = divisor;
            int temp = -1;

            while( ( value >= halfOfMinInt ) && ( dividend <= value + value ) ) {
                value += value;
                temp += temp;
            }

            divident -= value;
            quotient += temp;
        }

        if( negatives != 1 )
            return -quotient;
        return quotient;
    }
};
} // namespace


namespace {
/*
Approach 3: Adding Powers of Two

15 / 2
10 / 3

-10 / -2
quotient = 0

divisors:
-2, -4, -8
        ^

N - absolute value of dividend

Time O(logN)
Space O(logN)
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == std::numeric_limits< int >::min() && divisor == -1 )
            return std::numeric_limits< int >::max();

        const int halfOfMinInt = std::numeric_limits< int >::min() / 2;

        int negatives = 2;
        if( dividend > 0 ) {
            --negatives;
            dividend = -dividend;
        }
        if( divisor > 0 ) {
            --negatives;
            divisor = -divisor;
        }

        int quotient = 0;

        std::vector< int > divisors;
        int value = divisor;
        while( value >= dividend ) {
            divisors.push_back( value );
            if( value < halfOfMinInt )
                break;

            value += value;
        }

        for( int i = divisors.size() - 1; i >= 0; --i ) {
            if( divisors[ i ] >= dividend ) {
                quotient -= std::pow( 2, i );
                dividend -= divisors[ i ];
            }
        }

        if( negatives != 1)
            return -quotient;

        return quotient;
    }
};
} // namespace {
