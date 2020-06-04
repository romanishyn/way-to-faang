#include <iostream>

#include "leet_code/interval/56_m_merge_intervals/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cassert>


int main()
{
    V1::Solution solution;

    vector<vector<int>> input{ {{4,5},{1,4},{0,1}} };

    solution.merge( input );

    return 0;
}

