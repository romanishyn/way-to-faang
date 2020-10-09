/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

#include <vector>
#include <unordered_map>

using std::vector;

namespace {
/*
N - size of nums1
M - size of nums2

Time O(N + M)
Space O(min(N, M))
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > nums2.size() ) {
            return intersect( nums2, nums1 );
        }

        std::unordered_map< int, int > nums1Map;
        for( int num : nums1 ) {
            ++nums1Map[ num ];
        }

        int idx = 0;
        for( int num : nums2 ) {
            auto it = nums1Map.find( num );
            if( it != nums1Map.end() && it->second > 0 ) {
                nums1[ idx++ ] = num;
                --it->second;
            }
        }

        return std::vector< int >( nums1.begin(), nums1.begin() + idx );
    }
};
} // namespace

namespace {
/*
N - size of nums1
M - size of nums2

Time O(NlogN + MlogM)
Space O(1) if ignoring output
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort( nums1.begin(), nums1.end() );
        std::sort( nums2.begin(), nums2.end() );

        std::vector< int > result;
        int i = 0;
        int j = 0;
        while( i < nums1.size() && j < nums2.size() ) {
            if( nums1[ i ] < nums2[ j ] ) {
                ++i;
            }
            else if( nums1[ i ] > nums2[ j ] ) {
                ++j;
            }
            else {
                result.push_back( nums1[ i ] );
                ++i;
                ++j;
            }
        }

        return result;
    }
};
} // namespace