/*
https://leetcode.com/problems/max-consecutive-ones-iii/
*/

namespace {
/*
N - size of A

Time O(N)
Space O(1)
*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxLength = 0;

        for( int left = 0, right = 0; right < A.size(); ++right ) {
            if( A[ right ] == 0 )
                --K;

            while( K < 0 ) {
                if( A[ left ] == 0 )
                    ++K;

                ++left;
            }
            maxLength = std::max( maxLength, right - left + 1 );
        }

        return maxLength;
    }
};
} // namespace
