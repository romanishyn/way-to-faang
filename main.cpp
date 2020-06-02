#include <iostream>

#include "leet_code/graph/128_h_longest_consecutive_sequence/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cassert>


int main()
{
    V4::Solution solution;

    vector< int > v { 100,4,200,1,3,2 };
    std::cout << "RESULT: " << solution.longestConsecutive( v ) << std::endl;

    return 0;
}

