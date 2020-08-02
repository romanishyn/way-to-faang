/*
 * https://leetcode.com/problems/powx-n/
 * */

#include <limits>

namespace V1 {
/*
 * Fail in case of n is MIN_INT
 *
 * Time O(logn)
 * Space O(logn)
 * */
class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 )
            return 1;
        if( n < 0 ) {
            x = 1 / x;
            n = -n;
        }

        double half = myPow( x, n / 2 );

        return n % 2 ? half * half * x : half * half;
    }
};
} // namespace V1

namespace V2 {
/*
 * Explanation: https://leetcode.com/problems/powx-n/discuss/19546/Short-and-easy-to-understand-solution/19724
 *
 * Handle case of n is MIN_INT
 *
 * Time O(logn)
 * Space O(logn)
 * */
class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 )
            return 1;
        if( n == std::numeric_limits< int >::min() ) {
            n = n / 2;
            x = x * x;
        }
        if( n < 0 ) {
            x = 1 / x;
            n = -n;
        }

        double half = myPow( x, n / 2 );
        return n % 2 ? half * half * x : half * half;
    }
};
} // namespace V2
