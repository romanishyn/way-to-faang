#include <iostream>

#include "leet_code/design/trie.hpp"

// extract to string
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>

struct Print{
    Print() {
        std::cout << "constructor Print" << std::endl;
    }
    ~Print() {
        std::cout << "destructor Print" << std::endl;
    }

    std::string text= "text";
};

int main ()
{
//    Print p[ 5 ] = {};

    {
        V1::Trie trie;

        trie.insert( "hello" );
        assert( trie.search( "hello" ) );

        trie.insert( "helloworld" );
        assert( trie.search( "helloworld" ) );

//    new int;

        assert( !trie.search( "helll" ) );

        trie.insert( "hell" );
        assert( trie.search( "hell" ) );

        trie.insert( "h" );
        assert( trie.search( "h" ) );

        trie.remove( "hello" );
        assert( !trie.search( "hello" ) );

        assert( trie.search( "hell" ) );
        assert( trie.search( "helloworld" ) );

        trie.remove( "h" );
        assert( !trie.search( "h" ) );
        assert( trie.search( "hell" ) );
        assert( trie.search( "helloworld" ) );

        trie.remove( "helloworld" );
        assert( !trie.search( "helloworld" ) );
        assert( !trie.isEmpty() );
        assert( trie.search( "hell" ) );

        trie.remove( "hell" );
        assert( trie.isEmpty() );
        assert( !trie.search( "hell" ) );
    }

    {
        V1::Trie trie;

        trie.insertRecursive( "hello" );
        assert( trie.searchRecursive( "hello" ) );

        trie.insertRecursive( "helloworld" );
        assert( trie.searchRecursive( "helloworld" ) );

//    new int;

        assert( !trie.searchRecursive( "helll" ) );

        trie.insertRecursive( "hell" );
        assert( trie.searchRecursive( "hell" ) );

        trie.insertRecursive( "h" );
        assert( trie.searchRecursive( "h" ) );

        trie.remove( "hello" );
        assert( !trie.searchRecursive( "hello" ) );

        assert( trie.searchRecursive( "hell" ) );
        assert( trie.searchRecursive( "helloworld" ) );

        trie.remove( "h" );
        assert( !trie.searchRecursive( "h" ) );
        assert( trie.searchRecursive( "hell" ) );
        assert( trie.searchRecursive( "helloworld" ) );

        trie.remove( "helloworld" );
        assert( !trie.searchRecursive( "helloworld" ) );
        assert( !trie.isEmpty() );
        assert( trie.searchRecursive( "hell" ) );

        trie.remove( "hell" );
        assert( trie.isEmpty() );
        assert( !trie.searchRecursive( "hell" ) );
    }
    return 0;
}
