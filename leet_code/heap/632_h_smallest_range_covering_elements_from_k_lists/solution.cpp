/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/

#include <multiset>
#include <vector>

using std::vector;

namespace {
/*
Keep track of k list in sorted set. Min and max values in set are range.
Run while loop while set size equals nums size. At each iteration check if 
current range is less than range up to now, if so update range. Also extract
from set lowest element, move to the next one in list and push into set new
element;

K - size of nums
N - total number of elements

Time O(NlogK)
Space O(K)
*/
class Solution {
    struct Number {
        int value;
        int valueIdx;
        int listIdx;

        bool operator < ( const Number& rhs ) const {
            return value < rhs.value;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        std::multiset< Number > lists;
        for( int i = 0; i < nums.size(); ++i ) {
            lists.insert( { nums[ i ][ 0 ], 0, i } );
        }

        int left = lists.begin()->value;
        int right = lists.rbegin()->value;

        while( lists.size() == nums.size() ) {
            auto leftIt = lists.begin();
            auto rightIt = lists.rbegin();

            if( rightIt->value - leftIt->value < right - left ) {
                right = rightIt->value;
                left = leftIt->value;
            }
            else if( ( rightIt->value - leftIt->value == right - left ) && leftIt->value < left ) {
                right = rightIt->value;
                left = leftIt->value;
            }

            Number oldNumber = *leftIt;
            lists.erase( leftIt );
            oldNumber.valueIdx += 1;
            if( oldNumber.valueIdx < nums[ oldNumber.listIdx ].size() ) {
                oldNumber.value = nums[ oldNumber.listIdx ][ oldNumber.valueIdx ];
                lists.insert( oldNumber );
            }
        }

        return { left, right };
    }
};
} // namespace

namespace {
/*
*/
class Solution {
    using Data = std::pair< int/*val*/, std::pair< int/*listIdx*/, int/*valIdx*/ > >;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int beginRange = 0;
        int endRange = std::numeric_limits< int >::max();
        int currentMaxVal = std::numeric_limits< int >::min();

        auto comparator = []( const Data& lhs, const Data& rhs ) {
            return lhs.first > rhs.first;
        };
        std::priority_queue< Data, std::vector< Data >, decltype( comparator ) > minHeap( comparator );

        for( int i = 0; i < nums.size(); ++i ) {
            currentMaxVal = std::max( currentMaxVal, nums[ i ][ 0 ] );
            minHeap.push( { nums[ i ][ 0 ], pair{ i, 0 } } );
        }

        while( minHeap.size() == nums.size() ) {
            auto entry = minHeap.top();
            minHeap.pop();

            if( endRange - beginRange > currentMaxVal - entry.first ) {
                beginRange = entry.first;
                endRange = currentMaxVal;
            }

            entry.second.second++;
            if( nums[ entry.second.first ].size() > entry.second.second ) {
                entry.first = nums[ entry.second.first ][ entry.second.second ];
                minHeap.push( entry );
                currentMaxVal = std::max( currentMaxVal, entry.first );
            }
        }

        return { beginRange, endRange };
    }
};
} // namespace