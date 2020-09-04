/*
https://leetcode.com/problems/find-k-closest-elements/
*/

namespace {
/*
Solution based on maxHeap.
1. Using binary search (lower_bound) find position of X
2. Add all values [pos_x - k, pos_x + k] to the heap, maintaing size of heap not greater than k-closest-elements/
3. Extract all values from heap

N - size of arr
K - number of closes elements
X - target value

Time O(N*lonK)
Space O(K)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int findPos = std::distance( std::begin( arr ), std::lower_bound( std::begin( arr ), std::end( arr ), x ) );
        const int beginIdx = std::max( 0, findPos - k );
        const int endIdx = std::min( static_cast< int >( arr.size() ), findPos + k );

        auto comparator = [ x ]( int lhs, int rhs ) {
            const int diff1 = std::abs( lhs - x );
            const int diff2 = std::abs( rhs - x );
            
            if( diff1 == diff2 )
                return lhs < rhs;
            else
                return diff1 < diff2;
        };
        std::priority_queue< int, std::vector< int >, decltype( comparator ) > maxHeap( comparator );
        for( int i = beginIdx; i < endIdx; ++i ) {
            maxHeap.push( arr[ i ] );
            if( maxHeap.size() > k )
                maxHeap.pop();
        }

        std::vector< int > result;
        while( ! maxHeap.empty() ) {
            result.push_back( maxHeap.top() );
            maxHeap.pop();
        }
        std::sort( std::begin( result ), std::end( result ) );

        return result;
    }
};
} // namespace

namespace {
/*
Time O(logN + K)
Space O(K)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if( x < arr.front() )
            return { arr.begin(), std::next( arr.begin(), k ) };
        if( x > arr.back() )
            return { std::prev( arr.end(), k ), arr.end() };

        const int size = arr.size();
        int closestX = std::distance( arr.begin(), std::lower_bound( arr.begin(), arr.end(), x ) );

        int left = closestX - 1;
        int right = closestX;

        std::deque< int > deq;
        for( int i = 0; i < k; ++i ) {
            if( left >= 0 && right < size ) {
                const int diff1 = std::abs( arr[ left ] - x );
                const int diff2 = std::abs( arr[ right ] - x );

                if( diff1 <= diff2 )
                    deq.push_front( arr[ left-- ] );
                else
                    deq.push_back( arr[ right++ ] );
            }
            else if( left >= 0 )
                deq.push_front( arr[ left-- ] );
            else if( right < size )
                deq.push_back( arr[ right++ ] );
        }

        return { deq.begin(), deq.end() };
    }
};
} // namespace
