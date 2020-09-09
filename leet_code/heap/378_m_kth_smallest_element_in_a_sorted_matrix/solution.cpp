/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

#include <vector>
#include <queue>

using std::vector;

namespace {
/*

*/
class Solution {
    struct Number {
        int value;
        int rowIdx;
        int valueIdx;

        bool operator < ( const Number& rhs ) const {
            return value > rhs.value;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue< Number > minHeap;

        const int size = matrix.size();

        for( int i = 0; i < size; ++i ) {
            minHeap.push( { matrix[ i ][ 0 ], i, 0 } );
        }

        int counter = 0;
        int kthValue = 0;
        while( counter < k ) {
            auto number = minHeap.top();
            minHeap.pop();

            ++counter;
            kthValue = number.value;

            ++number.valueIdx;
            if( number.valueIdx < size ) {
                number.value = matrix[ number.rowIdx ][ number.valueIdx ];
                minHeap.push( number );
            }
        }

        return kthValue;
    }
};
} // namespace

namespace {
// TODO
// wrong solution
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix.front().front();
        int right = matrix.back().back();

        std::pair< int, int > range{ left, right };
        int ans = left;
        while( left <= right ) {
            int midValue = left + ( right - left ) / 2;
            int count = countLessOrEqual( matrix, midValue, range );

            if( count <= k ) {
                ans = range.first;
                left = range.second;
            }
            else {
                right = range.first;
            }
        }

        return ans;
    }

private:
    int countLessOrEqual( const vector<vector<int>>& matrix, int pivot, std::pair< int, int >& range ) {
        int count = 0;

        int row = 0;
        int col = matrix[ 0 ].size() - 1;

        while( row < matrix.size() && col >= 0 ) {
            int value = matrix[ row ][ col ];
            if( value <= pivot ) {
                range.first = std::max( range.first, value );

                count += col;
                ++row;
            }
            else {
                range.second = std::min( range.second, value );
                --col;
            }
        }

        return count;
    }
};
} // namespace
