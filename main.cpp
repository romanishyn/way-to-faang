#include <iostream>

#include "pramp/word_count_engine/solution.hpp"
#include "leet_code/array/15_m_3Sum/solution.hpp"

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
    V2::wordCountEngine( "Practice makes perfect, you'll get perfecT by practice. just practice! just just just!!" );
    std::vector< int > v( 0 );

    std::cout << "size: " << v.size() << std::endl;

    return 0;
}
