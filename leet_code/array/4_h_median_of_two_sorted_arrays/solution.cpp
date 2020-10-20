/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <vector>
#include <limits>

using std::vector;

namespace {
/*
M - size of nums1
N - size of nums2

Time O(M+N)
Space O(M+N)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int sizeNums1 = nums1.size();
        const int sizeNums2 = nums2.size();

        std::vector< int > mergedVector;

        int idx1 = 0;
        int idx2 = 0;
        while( idx1 < sizeNums1 && idx2 < sizeNums2 ) {
            int value = std::min( nums1[ idx1 ], nums2[ idx2 ] );
            if( nums1[ idx1 ] < nums2[ idx2 ] )
                ++idx1;
            else
                ++idx2;

            mergedVector.push_back( value );
        }
        std::copy( begin( nums1 ) + idx1, end( nums1 ), std::back_inserter( mergedVector ) );
        std::copy( begin( nums2 ) + idx2, end( nums2 ), std::back_inserter( mergedVector ) );

        const int mergedVectorSize = mergedVector.size();
        if( mergedVectorSize % 2 == 0 )
            return ( mergedVector[ mergedVectorSize / 2 - 1 ] + mergedVector[ mergedVectorSize / 2 ] ) / 2.0;
        else 
            return mergedVector[ mergedVectorSize / 2 ];
    }
};
} //namespace

namespace {
/*
Tushar:
Video: https://www.youtube.com/watch?v=LPFhl65R7ww
Text: https://github.com/mission-peace/interview/blob/master/src/com/interview/binarysearch/MedianOfTwoSortedArrayOfDifferentLength.java

N - size of nums1
M - size of nums2

Time O(log(min(N,M))
Space O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > nums2.size() )
            return findMedianSortedArrays( nums2, nums1 );

        const int sizeX = nums1.size();
        const int sizeY = nums2.size();

        int begin = 0;
        int end = sizeX;

        while( begin <= end ) {
            const int partitionX = ( begin + end ) / 2;
            const int partitionY = ( sizeX + sizeY + 1 ) / 2 - partitionX;

            const int maxLeftX = partitionX == 0 ? std::numeric_limits< int >::min() : nums1[ partitionX - 1 ];
            const int minRightX = partitionX == sizeX ? std::numeric_limits< int >::max() : nums1[ partitionX ];

            const int maxLeftY = partitionY == 0 ? std::numeric_limits< int >::min() : nums2[ partitionY - 1 ];
            const int minRightY = partitionY == sizeY ? std::numeric_limits< int >::max() : nums2[ partitionY ];

            if( ( maxLeftX <= minRightY ) && ( maxLeftY <= minRightX ) ) {
                if( ( sizeX + sizeY ) % 2 == 0 ) {
                    return ( std::max( maxLeftX, maxLeftY ) + std::min( minRightX, minRightY ) ) / 2.;
                }
                else {
                    return std::max( maxLeftX, maxLeftY );
                }
            }
            else if( maxLeftX > minRightY ) {
                end = partitionX;
            }
            else {
                begin = partitionX + 1;
            }
        }

        return 0; // Unreachable code
    }
};
} // namespace
