#include <iostream>

#include "pramp/word_count_engine/solution.hpp"
#include "leet_code/array/957_m_prison_cells_after_n_days/solution.hpp"

#include "leet_code/design/trie.hpp"

// extract to string
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>
#include <set>
#include <string_view>

#include <limits>

struct Functor {
    bool operator ()( int lhs, int rhs ) {
        return std::less<int>{}( lhs, rhs );
    }
};

template < typename  T >
class name;

int partition( std::vector< int >& values, int left, int right, int pivotIdx ) {
    int pivotValue = values[ pivotIdx ];
    std::swap( values[ right ], values[ pivotIdx ] );

    int leftPartEndIdx = left;
    for( int i = left; i < right; ++i ) {
        if( values[ i ] < pivotValue ) {
            std::swap( values[ i ], values[ leftPartEndIdx ] );
            ++leftPartEndIdx;
        }
    }

    std::swap( values[ leftPartEndIdx ], values[ right ] );

    return leftPartEndIdx;
}
int main ()
{
    std::vector< int > values{ 5, 3, 2, 7, 6 };
    std::cout << "nen idx: " << partition( values, 0, values.size() - 1, 2 ) << std::endl;
    for( int x : values )
        std::cout << x << ", ";
    std::cout << std::endl;
    return 0;
}
