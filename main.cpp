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

struct Functor {
    bool operator ()( int lhs, int rhs ) {
        return std::less<int>{}( lhs, rhs );
    }
};

template < typename  T >
class name;

int main ()
{
    V1::Solution solution;
    std::vector<int> cells{0,1,0,1,1,0,0,1 };
    solution.prisonAfterNDays( cells, 7 );


    return 0;
}
