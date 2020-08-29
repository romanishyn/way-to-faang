/*
https://leetcode.com/problems/pancake-sorting/
*/

#include <vector>
#include <functional>
#include <iterator>

using std::vector;

namespace {
/*
Using ordirnal Pancake Sort

N - size of A

Time O(N^2)
Space O(N), or O(1) ignoring output collection
*/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        std::vector< int > result;

        int k = A.size() - 1;
        while( k > 0 ) {
            int maxIdx = findMaxVal( A, k );
            flip( A, maxIdx );
            flip( A, k );

            result.push_back( maxIdx + 1 );
            result.push_back( k + 1 );
            --k;
        }

        return result;
    }

private:
    int findMaxVal( const std::vector< int >& arr, int k ) {
        int maxIdx = 0;
        int maxVal = arr[ 0 ];
        for( int i = 1; i <= k; ++i ) {
            if( maxVal < arr[ i ] ) {
                maxVal = arr[ i ];
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    void flip( std::vector< int >& arr, int k ) {
        int left = 0;
        int right = k;
        while( left < right ) {
            std::swap( arr[ left ], arr[ right ] );
            ++left;
            --right;
        }
    }
};
} // namespace

namespace {
/*
Ordinal Pancake Sort. Using STL functions

N - size of A

Time O(N^2)
Space O(N), or O(1) ignoring output collection
*/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        std::vector< int > result;

        for( int k = A.size(); k > 0; --k ) {
            auto maxIt = std::max_element( A.begin(), A.begin() + k );
            std::reverse( A.begin(), std::next( maxIt ) );
            std::reverse( A.begin(), std::next( A.begin(), k ) );

            result.push_back( std::distance( A.begin(), maxIt ) + 1 );
            result.push_back( k );
        }

        return result;
    }
};
} // namespace