#include <iostream>

#include "leet_code/graph/130_m_surrounded_regions/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>

int main()
{
//    vector< vector< char >> board =
//        {{'O','O','O','O','X','X'}
//        ,{'O','O','O','O','O','O'}
//        ,{'O','X','O','X','O','O'}
//        ,{'O','X','O','O','X','O'}
//        ,{'O','X','O','X','O','O'}
//        ,{'O','X','O','O','O','O'}};

    vector< vector< char >> board =
            {{'X','O','X','O','X','O'},
             {'O','X','O','X','O','X'},
             {'X','O','X','O','X','O'},
             {'O','X','O','X','O','X'}};

    vector< vector< char >> board3 =
            {{'O','X','X','O','X'},
             {'X','O','O','X','O'},
             {'X','O','X','O','X'},
             {'O','X','O','O','O'},
             {'X','X','O','X','O'}};
    Solution solution;
    solution.solve( board3 );
}

