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
#include <string_view>

struct Functor {
    bool operator ()( int lhs, int rhs ) {
        return std::less<int>{}( lhs, rhs );
    }
};

int main ()
{
    std::string_view text( "text" );
    std::cout << "p: " << text.substr( 1, text.size() ) << std::endl;


    return 0;
}
