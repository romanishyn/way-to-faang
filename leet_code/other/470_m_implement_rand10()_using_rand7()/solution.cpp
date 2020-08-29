/*
https://leetcode.com/problems/implement-rand10-using-rand7/
*/

namespace {
/*
Solution taken from: https://leetcode.com/problems/implement-rand10-using-rand7/discuss/816213/C%2B%2B-Simple-2-Steps-Solution-Explained-~100-Time-~60-Space
*/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int base = rand7();
        int seed = 7;

        while( base > 5 ) {
            seed = base - 5;
            base = rand7();
        }

        while( seed == 7 )
            seed = rand7();

        return ( seed % 2 ? 5 : 0 ) + base;
    }
};
} // namespace