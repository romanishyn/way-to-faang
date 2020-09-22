/*
https://leetcode.com/problems/car-pooling/
*/

#include <vector>

using std::vector;

namespace {
/*
Approach 1: Time Stamp

N - size of trips

Time O(NlogN)
Space O(N)
*/
class Solution {
    using Trip = vector< int >;
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        auto sortComparator = []( const Trip& t1, const Trip& t2 ) {
            return t1[ 1 ] < t2[ 1 ];
        };
        std::sort( trips.begin(), trips.end(), sortComparator );
        
        auto minComparator = []( const Trip& t1, const Trip& t2 ) {
            return t1[ 2 ] > t2[ 2 ];
        };
        std::priority_queue< Trip, std::vector< Trip >, decltype( minComparator ) > minHeap( minComparator );
        
        int currCapacity = 0;
        for( int i = 0; i < trips.size(); ++i ) {
            while( ! minHeap.empty() && minHeap.top()[ 2 ] <= trips[ i ][ 1 ] ) {
                currCapacity -= minHeap.top()[ 0 ];
                minHeap.pop();
            }
            
            minHeap.push( trips[ i ] );
            currCapacity += trips[ i ][ 0 ];
            if( currCapacity > capacity )
                return false;
        }
        
        return true;
    }
};
} // namespace

namespace {
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector< int > timestamps( 1001 );
        for( const auto& trip : trips ) {
            timestamps[ trip[ 1 ] ] += trip[ 0 ];
            timestamps[ trip[ 2 ] ] -= trip[ 0 ];
        }

        int currentCapacity = 0;
        for( int num : timestamps ) {
            currentCapacity += num;
            if( currentCapacity > capacity )
                return false;
        }

        return true;
    }
};
} // namespace