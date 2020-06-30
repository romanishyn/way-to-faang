#include <iostream>

#include "leet_code/heap/347_m_top_k_frequent_elements/solution.hpp"

#include "leet_code/design/trie.hpp"

// extract to string
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>
#include <set>

struct Functor {
    bool operator ()( int lhs, int rhs ) {
        return std::less<int>{}( lhs, rhs );
    }
};

int main ()
{
    std::vector< int > v( 0 );

    std::cout << "size: " << v.size() << std::endl;

    return 0;
}
