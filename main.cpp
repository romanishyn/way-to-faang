#include <iostream>

#include "leet_code/interval/57_h_insert_interval/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cassert>


int main()
{
//    std::vector<int> v{12,15,17,19,20,22,23,26,29,35,40,51};
    std::vector<int> v{1,3,6,9};

    V2::Solution solution;

    vector<vector<int>> input{ { 1, 3 }, { 6, 9 } };
    vector<int> interval{ 2, 5 };
    solution.insert( input, interval );

    // Print vector
    std::cout << "Vector contains :";
    for (int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";

    std::vector<int>::iterator upper1, upper2;

    // std :: upper_bound
    upper1 = std::lower_bound(v.begin(), v.end(), 2);
    upper2 = std::upper_bound(v.begin(), v.end(), 2);

    if ( upper1 == v.end() )
        std::cout << "end;" << std::endl;

    std::cout << "lower : " << *upper1 << std::endl;
    std::cout << "upper : " << *upper2 << std::endl;

//    std::cout << "\nupper_bound for element 35 is at position : "
//              << (upper1 - v.begin());
//    std::cout << "\nupper_bound for element 45 is at position : "
//              << (upper2 - v.begin());

    return 0;
}

