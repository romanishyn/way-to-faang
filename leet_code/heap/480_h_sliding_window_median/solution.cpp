/*
 * https://leetcode.com/problems/sliding-window-median/
 * */

#include <vector>
#include <algorithm>

using std::vector;

namespace V1 {
/*
 * LC: Time Limit Exceeded
 *
 * N - size of nums
 * K - value of k
 *
 * Time (NK)
 * Space (K) if we are ignoring output vector
 * */
class Solution {
public:
    vector< double > medianSlidingWindow( vector< int > & nums, int k ) {
        vector< double > result;

        int left = 0;
        for( int end = 0; end < nums.size(); ++end ) {
            if( end - left + 1 == k ) {
                vector< int > window( nums.begin() + left, nums.begin() + left + k );

                int midIdx = window.size() / 2;
                if( k & 1 ) {
                    std::nth_element( window.begin(), window.begin() + midIdx, window.end() );
                    result.push_back( window[ midIdx ] );
                }
                else {
                    std::nth_element( window.begin(), window.begin() + midIdx, window.end() );
                    int val1 = window[ midIdx ];
                    std::nth_element( window.begin(), window.begin() + midIdx - 1, window.end() );
                    int val2 = window[ midIdx - 1 ];

                    result.push_back( val1 + ( val2 - val1 ) / 2.0 ); // NOTE: "val1 + ( val2 - val1 ) / 2.0 " not ( val1 + val2 ) / 2.0
                }

                ++left;
            }
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
// TODO: implement using Two Heap Approach
} // namespace V2