/*
https://leetcode.com/problems/sliding-window-maximum/submissions/
*/

#include <vector>
#include <map>
#include <deque>

using std::vector;

namespace {
/*
N - size of nums
K - size of window

Time O(N*logK)
Space O(K) or O(N)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector< int > result;

        std::map< int, int > valToFreq;

        for( int left = 0, right = 0; right < nums.size(); ++right ) {
            ++valToFreq[ nums[ right ] ];

            if( right - left + 1 > k ) {
                auto it = valToFreq.find( nums[ left ] );
                if( --it->second == 0 )
                    valToFreq.erase( it );
                
                ++left;
            }

            if( right - left + 1 == k ) {
                result.push_back( valToFreq.rbegin()->first );
            }
        }

        return result;
    }
};
} // namespace

namespace {
/*
N - size of nums
K - size of window

Time O(N)
Space O(K)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if( nums.empty() || k < 1 || k > nums.size() )
            return {};

        std::vector< int > result;
        std::deque< int > deq;

        for( int i = 0; i < nums.size(); ++i ) {
            while( ! deq.empty() && deq.front() <= i - k )
                deq.pop_front();

            while( ! deq.empty() && nums[ deq.back() ] <= nums[ i ] )
                deq.pop_back();

            deq.push_back( i );

            if( i >= k - 1 )
                result.push_back( nums[ deq.front() ] );
        }

        return result;
    }
};
} // namespace