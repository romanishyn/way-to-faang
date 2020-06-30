/*
https://leetcode.com/problems/top-k-frequent-elements/
*/

#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using std::vector;

namespace V1 {
/*
 * Based on Bucket Sort
 *
 * To count occurrences for each unique element we use unordered_map, key is an element, and value is the count of occurrences.
 * During iteration over nums we track of maximum count of occurrences.
 * Then we need to find top k values in the map, and keys corresponding to these values add to result vector.
 * To find this top, we use sort similar to bucket sort. Create vector of vector of integers, the main vector will have
 * size of maximum count of occurrences, call the main vector sort. Then iterate over map and value is index and key we push back to the vector by this index.
 * Next operation is final. We iterate over sort vector in reverse order, and while current subvector is not empty and result vector is less than k we continue
 * considering sort vector. At the and, return result vector.
 *
 * N is size of input vector
 *
 * Time (N)
 * Space (N)
 * */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map< int, int > map;
        int maxOccurrences = 0;
        for( int num : nums ) {
            ++map[ num ];
            maxOccurrences = std::max( maxOccurrences, map[ num ] );
        }

        std::vector< std::vector< int >> sort( maxOccurrences );
        for( auto [ key, value ] : map ) {
            sort[ value - 1 ].push_back( key );
        }

        std::vector< int > result;
        for( int i = maxOccurrences - 1; i >= 0; --i ) {
            while( !sort[ i ].empty() && result.size() < k ) {
                result.push_back( sort[ i ].back() );
                sort[ i ].pop_back();
            }
        }

        return result;
    }
};
} // namespace V1


namespace V2 {
/*
 * Based on unordered_map + priority_queue (min)
 *
 * Time (Nlogk)
 * Space (N)
 * */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map< int, int > map;
        for( int num : nums )
            ++map[ num ];

        using MapIterator = decltype( map )::iterator;
        auto comp = []( const MapIterator& lhs, const MapIterator& rhs ) { return lhs->second > rhs->second ; };

        std::priority_queue< MapIterator, std::vector< MapIterator >, decltype( comp ) > queue( comp );
        for( auto it = map.begin(); it != map.end(); ++it ) {
            queue.push( it );
            if( queue.size() > k )
                queue.pop();
        }

        std::vector< int > result;
        while( !queue.empty() ) {
            result.push_back( queue.top()->first );
            queue.pop();
        }

        return result;
    }
};
} // namespace V2

namespace V3 {
/*
 * Based on unordered_map + std::nth_element
 *
 * We need count occurrences for each unique element, then take k most frequent elements and push then to result vector.
 * 1) Create and populate map, where key is a unique number, value is a number of occurrences
 * 2) Create and fill vector with keys from map.
 * 3) Do partial vector sorting first kth elements, on the left side will be elements bigger than on the right
 * 4) Remove right part of vector and return result;
 *
 * Time (N), O(std::nth_element(N)) is linear
 * Space (N)
 * */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map< int, int > map;
        for( int num : nums )
            ++map[ num ];

        std::vector< int > result;
        for( auto [ key, _ ] : map )
            result.push_back( key );

        auto comp = [&map]( int lhs, int rhs ) {
            return map[ lhs ] > map[ rhs ];
        };
        std::nth_element( result.begin(), result.begin() + k - 1, result.end(), comp );

        result.resize( k );

        return result;
    }
};
}
