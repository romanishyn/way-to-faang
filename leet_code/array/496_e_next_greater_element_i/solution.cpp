/*
https://leetcode.com/problems/next-greater-element-i/
*/

#include <vector>
#include <unorderd_map>
#include <stack>

using std::vector;

namespace {
/*
N - nums1
M - nums2

Time O(N + M)
Space O(N + M)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack< int > stack;
        std::unorderd_map< int, int > valToGreaterIdx;
        for( int i = 0; i < nums2.size(); ++i ) {
            while( ! stack.empty() && nums2[ stack.top() ] < nums2[ i ] ) {
                valToGreaterIdx[ nums2[ stack.top() ] = i;
                stack.pop();
            }
            stack.push( i );
        }

        std::vector< int > result;
        for( int num : nums1 ) {
            int value = -1;
            if( auto it = valToGreaterIdx.find( num ); it != valToGreaterIdx.end() ) {
                value = nums2[ it->second ];
            }
            result.push_back( value );
        }

        return result;
    }
};
} // namespace
