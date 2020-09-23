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

namespace {
/*
https://leetcode.com/problems/implement-rand10-using-rand7/discuss/150301/Three-line-Java-solution-the-idea-can-be-generalized-to-"Implement-RandM()-Using-RandN()"/246718
https://leetcode.com/problems/implement-rand10-using-rand7/discuss/150301/Three-line-Java-solution-the-idea-can-be-generalized-to-"Implement-RandM()-Using-RandN()"/329534
*/
class Solution {
public:
    int rand10() {
        int num = 49;
        do {
            int row = rand7();
            int col = rand7();

            num = col + ( row - 1 ) * 7;
        } while( num > 40 );

        return num % 10 + 1;
    }
};
} // namespace