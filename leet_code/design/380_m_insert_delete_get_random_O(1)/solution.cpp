/*
https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

#include <vector>
#include <unordered_map>
#include <cstdlib>

namespace {
/*
N - number of unique values at each moment

Time O(1) - insert, remove, getRandom
Space O(N)
*/
class RandomizedSet {
    std::vector< int > values;
    std::unordered_map< int/*val*/, int/*idx*/ > valToIdx;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        std::srand( std::time( nullptr ) );
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = valToIdx.find( val );
        if( it != valToIdx.end() )
            return false;

        valToIdx.try_emplace( val, values.size() );
        values.push_back( val );
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = valToIdx.find( val );
        if( it == valToIdx.end() )
            return false;

        auto idx = it->second;
        std::swap( values[ idx ], values.back() );
        valToIdx.insert_or_assign( values[ idx ], idx );

        values.pop_back();
        valToIdx.erase( val );

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return values[ std::rand() % values.size() ];
    }
};
} // namespace
