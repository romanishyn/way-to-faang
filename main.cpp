#include <iostream>

#include "leet_code/array/11_m_container_with_most_water/solution.hpp"

#include <vector>

int main()
{
    int a = -1;
    int b = -2;

    int result = 0;
    bool carry = false;

    for( int i = 0; i < 32; ++i ) {
        const bool isAOne = static_cast< bool >( a & ( 1 << i ) );
        const bool isBOne = static_cast< bool >( b & ( 1 << i ) );

        if( isAOne && isBOne ) {
            if( carry )
                result |= 1 << i;

            carry = true;
        } else if( !isAOne && !isBOne ) {
            if( carry )
                result |= 1 << i;

            carry = false;
        } else {
            if( !carry )
                result |= 1 << i;
        }
    }

    std::cout << "result: " << result << std::endl;

//    std::cout << sizeof(num) << std::endl;
    return 0;
}
