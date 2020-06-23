#include <iostream>

#include "leet_code/list/23_merge_k_sorted_lists/solution.hpp"

// extract to string
#include <iostream>
#include <string>
#include <sstream>

int main ()
{
    std::string name;

    std::stringstream stream( "" );

    std::cout << (stream ? "1 t" : "1 f" ) << std::endl;
    std::getline (stream,name, ',');
    std::cout << (stream ? "2 t" : "2 f" ) << std::endl;
    std::getline (stream,name, ',');
    std::cout << (stream ? "3 t" : "3 f" ) << std::endl;

    std::cout << "Hello, " << name << "!\n";

    return 0;
}
