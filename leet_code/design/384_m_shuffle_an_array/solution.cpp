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

namespace {
/*
Naive approach, this one generates output with no equal probability

Time O(N)
Space O(N)
*/
class Solution {
    const std::vector< int > data;
public:
    Solution(vector<int>& nums)
    : data{ nums }
    {
        std::srand( std::time( nullptr ) );
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector< int > result = data;
        for( int i = 0; i < result.size(); ++i ) {
            std::swap( result[ i ], result[ std::rand() % result.size() ] );
        }
        return result;
    }
};
} // namespace


namespace {
/*
Explanation: https://medium.com/@oldwestaction/randomness-is-hard-e085decbcbb2
Fisher–Yates shuffle or Knuth shuffle
*/
class Solution {
    const std::vector< int > data;

public:
    Solution(vector<int>& nums)
    : data{ nums }
    {
        std::srand( std::time( nullptr ) );
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto result = data;
        for( int i = result.size() - 1; i >= 0; --i ) {
            std::swap( result[ i ], result[ std::rand() % ( i + 1 ) ] );
        }
        return result;
    }
};
} // namespace