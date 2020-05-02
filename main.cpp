#include <iostream>

#include "leet_code/graph/topological_sort.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>

int main()
{
    Graph graph{
                { 2 }
            ,   { 2, 3 }
            ,   { 4 }
            ,   { 5 }
            ,   { 5 }
            ,   { 6 }
            ,   {}
    };

    Vector vector = sortDfs( graph );

    for( int v : vector )
        std::cout << v << ", ";
    std::cout << std::endl;

    vector = sortBfs( graph );
    for( int v : vector )
        std::cout << v << ", ";
    std::cout << std::endl;
}

