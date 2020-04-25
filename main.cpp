#include <iostream>

#include "leet_code/graph/133_m_clone_graph/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>


class A {
public:
    A() {}
    operator int() { return 42; }
};

int num = 0;

int main()
{
    A(num);
    std::cout << num << std::endl;
}

