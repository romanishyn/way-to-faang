/*
https://leetcode.com/problems/arranging-coins/
*/

#pragma once

namespace V1 {
/*
 * We can subtract from n, starting from 1 to n, while n is greater than i, and count how many times we subtracted value.
 *
 * Time ???
 * Space (1)
 * */
class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        for( int i = 1; i <= n; ++i ) {
            n -= i;
            ++count;
        }
        return count;
    }
};
} // namespace V1

namespace V2 {
/*
 * Here we need find some position in "sorted" sequence, so we can use binary search.
 * To understand if current position is possible best solution we will use Gauss's formula. k(k +1 )/2
 * If this sum is less or equal n, that means it possible solution. And move left pointer to mid+1, otherwise right to mid-1
 * At the end we return (left - 1), we need subtract -1 to bring back to the last valid position
 *
 * N - n
 * Time (logN)
 * Space (1)
 * */
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1;
        long right = n;

        while( left <= right ) {
            long mid = left + ( right - left ) / 2;

            if( ( mid * ( mid + 1 ) / 2 ) <= n )
                left = mid + 1;
            else
                right = mid - 1;
        }

        return static_cast< int >( left - 1 );
    }
};
} // namespace V2
