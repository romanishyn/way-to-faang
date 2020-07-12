/*
 * https://leetcode.com/problems/3sum-closest/
 * */

#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

namespace V1 {
/*
 * Time (N^2)
 * Space (1)
 * */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort( nums.begin(), nums.end() );

        int bestSum = nums[ 0 ] + nums[ 1 ] + nums[ 2 ];

        const int size = nums.size();
        for( int i = 0; i < size - 2; ++i ) {
            int left = i + 1;
            int right = size - 1;

            while( left < right ) {
                const int curSum = nums[ i ] + nums[ left ] + nums[ right ];

                if( curSum == target )
                    return curSum;

                bestSum = getCloserValue( target, curSum, bestSum );

                if( curSum > target )
                    --right;
                else
                    ++left;
            }
        }

        return bestSum;
    }

private:
    int getCloserValue( int target, int val1, int val2 ) {
        const int diff1 = std::abs( target - val1 );
        const int diff2 = std::abs( target - val2 );

        if( diff1 == diff2 )
            return val1 < val2 ? val1 : val2;
        else
            return diff1 < diff2 ? val1 : val2;
    }
};
} // namespace V1