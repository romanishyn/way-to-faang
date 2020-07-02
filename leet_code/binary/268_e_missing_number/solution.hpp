/*
https://leetcode.com/problems/missing-number/
*/

#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using std::vector;

namespace V1 {
/*
 * The idea is sum up number in range from zero to n, then extract all values from nums. Result is a answer.
 * Possible integer overflow.
 *
 * Time (2N) -> (N)
 * Space (1)
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum{ 0 };

        for( int i = 0; i <= nums.size(); ++i )
            sum += i;

        for( int n : nums )
            sum -= n;

        return sum;
    }
};
} // namespace V1

namespace V2 {
/* Good explanation: https://leetcode.com/problems/missing-number/discuss/69777/C++-solution-using-bit-manipulation/196136
 *
 * The basic is using XOR operation. We know that xor operation with the same values will produce zero.
 * In solution we apply XOR for each values from nums and for all index from 0 to n (initial value of number will be size of nums means N)
 * If there is no missed value, result will be zero, otherwise what left finally is the missing number.
 *
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::size_t number = nums.size();

        for( std::size_t i = 0; i < nums.size(); ++i ) {
            number ^= nums[ i ];
            number ^= i;
        }

        return number;
    }
};
} // namespace V2

namespace V3 {
/*
 * The main idea is using Gauss's formula
 *
 * N - size of nums
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const long expectedSum = nums.size() * ( nums.size() + 1 ) / 2;
        long actualSum = std::accumulate( nums.begin(), nums.end(), long{} );

        return static_cast< int >( expectedSum - actualSum );
    }
};
} // namespace V3
