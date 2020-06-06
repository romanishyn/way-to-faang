#include <iostream>

#include "leet_code/list/21_e_merge_two_sorted_lists/solution.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <cassert>


int main()
{
    V2::Solution solution;

    ListNode listNode4( 4 );
    ListNode listNode2( 2, &listNode4 );
    ListNode listNode1( 1, &listNode2 );

    ListNode listNode4_2( 4 );
    ListNode listNode3_2( 3, &listNode4_2 );
    ListNode listNode1_2( 1, &listNode3_2 );

    auto res = solution.mergeTwoLists( &listNode1, &listNode1_2 );

    while( res ) {
        std::cout << res->val << ", ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}

