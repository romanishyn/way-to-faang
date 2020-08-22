/*
https://leetcode.com/problems/sort-array-by-parity/
*/

#include <vector>

using std::vector;

namespace {
/*
Implement function similar to std::remove
On the left side all even values, beetwen left and right pointers are odd values

N - length of array

Time O(N)
Space O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for( int left = 0, right = 0; right < A.size(); ++right ) {
            if( A[ right ] % 2 == 0 ) {
                std::swap( A[ left ], A[ right ] );
                ++left;
            }
        }

        return A;
    }
};
} // namespace

namespace {
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        while( left < right ) {
            if( A[ right ] % 2 == 0 ) {
                std::swap( A[ left ], A[ right ] );
                ++left;
            }
            else {
                --right;
            }
        }

        return A;
    }
};
}