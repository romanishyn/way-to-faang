#include <iostream>

#include "leet_code/array/152_m_maximum_product_subarray/solution.hpp"

#include <vector>

int main()
{
    Solution solution;
    std::vector< int > nums{2,3,-2,4};
    std::cout << solution.maxProduct( nums ) << std::endl;
    return 0;
}