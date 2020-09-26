/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(1)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int size = nums.size();

        int left = 0;
        int right = size - 1;

        std::srand( std::time( nullptr ) );

        while( true ) {
            const int pivotIdx = left + ( std::rand() % ( right - left + 1 ) );
            const int pivotValueIdx = partition( nums, left, right, pivotIdx );

            if( size - k == pivotValueIdx )
                return nums[ pivotValueIdx ];

            if( size - k > pivotValueIdx )
                left = pivotValueIdx + 1;
            else
                right = pivotValueIdx - 1;
        }

        return nums.front();
    }

private:
    int partition( std::vector< int > & nums, int left, int right, int pivotIdx ) {
        std::swap( nums[ right ], nums[ pivotIdx ] );
        const int pivotVal = nums[ right ];

        int lesserItemsEndIdx = left;
        for( int i = left; i < right; ++i ) {
            if( nums[ i ] < pivotVal ) {
                std::swap( nums[ i ], nums[ lesserItemsEndIdx ] );
                ++lesserItemsEndIdx;
            }
        }

        std::swap( nums[ right ], nums[ lesserItemsEndIdx ] );

        return lesserItemsEndIdx;
    }
};
} // namespace

namespace {
/*
N - size of nums

Time O(NlogK)
Space O(K)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue< int, std::vector< int >, std::greater< int > > minHeap;

        for( int i = 0; i < k; ++i )
            minHeap.push( nums[ i ] );

        for( int i = k; i < nums.size(); ++i ) {
            if( nums[ i ] > minHeap.top() ) {
                minHeap.pop();
                minHeap.push( nums[ i ] );
            }
        }

        return minHeap.top();
    }
};
} // namespace
