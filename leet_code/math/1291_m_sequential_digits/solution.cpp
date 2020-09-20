/*
https://leetcode.com/problems/sequential-digits/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
Generate all possible answers

Time O(1)
Space O(1)
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        constexpr int numberOfDigits = 10;

        std::vector< int > result;
        
        for( int i = 1; i < numberOfDigits; ++i ) {
            int num = i;
            for( int j = i + 1; j < numberOfDigits; ++j ) {
                num *= 10;
                num += j;

                if( low <= num && num <= high )
                    result.push_back( num );
            }
        }

        std::sort( result.begin(), result.end() );

        return result;
    }
};
} // namespace

namespace {
/*
Hardcode all possible answers

Time O(1)
Space O(1)
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int nums[] = {
            12, 23, 34, 45, 56, 67, 78, 89,
            123, 234, 345, 456, 567, 678, 789,
            1234, 2345, 3456, 4567, 5678, 6789,
            12345, 23456, 34567, 45678, 56789,
            123456, 234567, 345678, 456789,
            1234567, 2345678, 3456789,
            12345678, 23456789,
            123456789,
        };

        std::vector< int > result;
        for( int num : nums ) {
            if( low <= num && num <= high )
                result.push_back( num );
        }

        return result;
    }
};
} // namespace
