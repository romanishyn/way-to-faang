/*
https://leetcode.com/problems/random-pick-with-weight/
*/

#include <vector>

using std::vector;

namespace {
/*
N - size of w

Constructor: Time O(N)
pickIndex:   Time O(logN)
Space O(N)
*/
class Solution {
    std::vector< int > m_prefixSum;
public:
    Solution(vector<int>& w){
        std::srand( std::time( nullptr ) );

        std::partial_sum( w.begin(), w.end(), std::back_inserter( m_prefixSum ) );
    }

    int pickIndex() {
        int value = ( std::rand() % m_prefixSum.back() ) + 1;

        return lowerBound( m_prefixSum, value );
    }

private:
    int lowerBound( const std::vector< int >& nums, int key ) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();

        while( left <= right ) {
            const int midIdx = left + ( right - left ) / 2;

            if( nums[ midIdx ] >= key ) {
                ans = midIdx;
                right = midIdx - 1;
            }
            else  {
                left = midIdx + 1;
            }
        }

        return ans;
    }
};
} // namespace

namespace {
/*
N - size of w

Constructor: Time O(N)
pickIndex:   Time O(logN)
Space O(N)
*/
class Solution {
    std::vector< int > data;

    int lowerBound( const std::vector< int > & nums, int key ) {
        int idx = -1;
        int left = 0;
        int right = nums.size() - 1;

        while( left <= right ) {
            int mid = left + ( right - left ) / 2;

            if( nums[ mid ] >= key ) {
                idx = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return idx;
    }

public:
    Solution(vector<int>& w) {
        std::srand( std::time( nullptr ) );
        std::partial_sum( begin( w ), end( w ), std::back_inserter( data ) );
    }

    int pickIndex() {
        const int weight = ( std::rand() % data.back() ) + 1;
        return lowerBound( data, weight );
    }
};
} // namespace
