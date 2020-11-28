/*
https://leetcode.com/problems/shuffle-an-array/
*/

#include <vector>
#include <crand>

using std::vector;

namespace {
/*
N - size of nums

Time O(N)
Space O(N)
*/
class Solution {
    std::vector< int > original;

public:
    Solution(vector<int>& nums)
    :   original{ nums }
    {
        std::srand( std::time( nullptr ) );
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto derived = original;
        for( int i = derived.size() - 1; i >= 0; --i ) {
            std::swap( derived[ i ], derived[ std::rand() % ( i + 1 ) ] );
        }
    
        return derived;
    }
};

} // namespace
