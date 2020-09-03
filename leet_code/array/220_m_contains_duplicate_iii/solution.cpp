/*
https://leetcode.com/problems/contains-duplicate-iii/
*/

namespace {
/*
Check each element with previous k elements, if any absolute different equals or less than t return true.
If haven't found such pair return false;

NOTE: possible interger overflow:
[-1,2147483647]
1
2147483647

N - number of elements
K - diff between indices

Time O(N*K)
Space O(1)
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for( int i = 0; i < nums.size(); ++i ) {
            for( int j = std::max( 0, i - k ); j < i; ++j ) {
                if( std::abs( static_cast< long >( nums[ i ] ) - nums[ j ] ) <= t )
                    return true;
            }
        }
        return false;
    }
};
} // namespace

namespace {
/*
Time (NlogK)
Space (K)
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        std::set< long > subarray;

        for( int i = 0; i < nums.size(); ++i ) {
            long val = nums[ i ];
            auto it = subarray.lower_bound( val - t );
            if( it != subarray.end() && std::abs( *it - val ) <= t )
                return true;

            subarray.insert( val );
            if( subarray.size() > k )
                subarray.erase( nums[ i - k ] );
        }

        return false;
    }
};
} // namespace