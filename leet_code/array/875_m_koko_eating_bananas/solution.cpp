/*
https://leetcode.com/problems/koko-eating-bananas/
*/

#include <vector>
#include <algorithm>

using std::vector;

namespace {
/*
N - size of piles
W - max value in piles

Time O(NlogW)
Space O(1)
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
        int right = *std::max_element( begin( piles ), end( piles ) );
        int ans = right;

        while( left <= right ) {
            const int mid = left + ( right - left ) / 2;
            if( canEat( piles, mid, H ) ) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canEat( const std::vector< int >& piles, int banansPerHour, int hours ) {
        int elapsedHours = 0;
        for( int bananas : piles ) {
            elapsedHours += ( bananas + banansPerHour - 1 ) / banansPerHour;
            if( elapsedHours > hours )
                return false;
        }
        return true;
    }
};
} // namespace
