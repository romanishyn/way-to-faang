/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
LC: TLE

Time O(k^2*logk)
Space O(k)
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using Pair = std::vector< int >;
        auto comparator = []( const Pair& lhs, const Pair& rhs ) {
            return ( lhs[ 0 ] + lhs[ 1 ] ) < ( rhs[ 0 ] + rhs[ 1 ] );
        };
        std::vector< Pair > result;
        for( int i = 0; i < nums1.size() && i < k; ++i ) {
            for( int j = 0; j < nums2.size() && j < k; ++j ) {
                result.push_back( { nums1[ i ], nums2[ j ] } );
                std::push_heap( result.begin(), result.end(), comparator );
                if( result.size() > k ) {
                    std::pop_heap( result.begin(), result.end(), comparator );
                    result.pop_back();
                }
            }
        }
        return result;
    }
};
} // namespace

namespace {
/*
Optimized previous solution

Time O(k^2*logk)
Space O(k)
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using Pair = std::vector< int >;
        auto comparator = []( const Pair& lhs, const Pair& rhs ) {
            return ( lhs[ 0 ] + lhs[ 1 ] ) < ( rhs[ 0 ] + rhs[ 1 ] );
        };

        std::vector< Pair > result;

        for( int i = 0; i < nums1.size() && i < k; ++i ) {
            for( int j = 0; j < nums2.size() && j < k; ++j ) {
                if( result.size() < k ) {
                    result.push_back( { nums1[ i ], nums2[ j ] } );
                    std::push_heap( result.begin(), result.end(), comparator );
                }
                else {
                    if( comparator( result.front(), { nums1[ i ], nums2[ j ] } ) ) {
                        break;
                    }
                    else {
                        std::pop_heap( result.begin(), result.end(), comparator );
                        result.pop_back();
                        result.push_back( { nums1[ i ], nums2[ j ] } );
                        std::push_heap( result.begin(), result.end(), comparator );
                    }
                }
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
Good explanation: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation

Time O(klogk)
Space O(k)
*/
class Solution {
    struct Node {
        int value1;
        int value2;
        int value2Idx;
        
        bool operator < ( const Node& rhs ) const {
            return ( value1 + value2 ) > ( rhs.value1 + rhs.value2 );
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if( nums1.empty() || nums2.empty() )
            return result;

        std::priority_queue< Node > minHeap;
        for( int i = 0; i < nums1.size() && i < k; ++i ) {
            minHeap.push( { nums1[ i ], nums2[ 0 ], 0 } );
        }

        while( k > 0 && ! minHeap.empty() ) {
            auto node = minHeap.top();
            minHeap.pop();
            
            result.push_back( { node.value1, node.value2 } );

            node.value2Idx++;
            if( node.value2Idx < nums2.size() ) {
                node.value2 = nums2[ node.value2Idx ];
                minHeap.push( node );
            }
            
            --k;
        }

        return result;
    }
};
} // namespace