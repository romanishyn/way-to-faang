/*
 * https://leetcode.com/problems/find-the-duplicate-number/
 * */

#include <vector>

using std::vector;

namespace V1 {
/*
 * Good explanation on educative
 *
 * Based on cycle sort.
 * We sort gived array, and when come across situation when current idx is not equal to idx of target position of current value
 * and new place has the same value, that means we have found duplication, so we can return value pointed by current idx
 *
 * N - size of input array
 *
 * Space (1)
 * Time (N)
 * */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while( i < nums.size() ) {
            int j = nums[ i ] - 1;
            if( i !=j && nums[ i ] == nums[ j ] )
                return nums[ i ];

            if( i != j )
                std::swap( nums[ i ], nums[ j ] );
            else
                ++i;
        }

        return -1; // unreachable state
    }
};
} // namespace V1

namespace V2 {
/*
 * Based on Floyd's algorithm
 *
 * Нужно быть внимательным что начальые значение должны быть одинаковые, второй цикл другой, нужно вернуть slow или fast
 * а не значение по этому указателю.
 *
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[ slow ];
            fast = nums[ nums[ fast ] ];
        } while( slow != fast );

        fast = 0;
        while( slow != fast ) {

            slow = nums[ slow ];
            fast = nums[ fast ];
        }

        return slow;
    }
};
} // namespace V2