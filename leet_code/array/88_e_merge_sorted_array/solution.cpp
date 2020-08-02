/*
 * https://leetcode.com/problems/merge-sorted-array/
 * */

#include <vector>
#include <algorithm>

using std::vector;

namespace V1 {
/*
 * Nums1 has capacity m + n, and both arrays are sorted, so we can start overwrite nums1 from the end.
 * Set pointer idx at the end of nums1, to track the position of an added element.
 *
 * Time O(M + N)
 * Space O(1)
 * */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        while( p1 >= 0 && p2 >= 0 ) {
            if( nums1[ p1 ] > nums2[ p2 ] )
                nums1[ idx ] = nums1[ p1-- ];
            else
                nums1[ idx ] = nums2[ p2-- ];

            --idx;

            // nums1[ idx-- ] = nums1[ p1 ] > nums2[ p2 ] ? nums1[ p1-- ] : nums2[ p2--];
        }

        std::copy_n( nums2.begin(), p2 + 1, nums1.begin() );
    }
};
}