/*
 * https://leetcode.com/problems/plus-one/
 */

#include <vector>

using std::vector;

namespace V1 {
/*
 * Here we worry about carry. We start out with index size - 1, since lest signigicant digit is on the left side of vector.
 * Then at each iteration we add carry to each digit, update carry - divide y 10, and then update current digit
 * reminder of division by 10. After loop we check if we still have what need to add, if so, then insert carry in left of vector.
 *
 * N - length of digits
 *
 * Time(N), we should visit all values in digits
 * Space(1), since we used only a constant amount of space throughout the algorithm
 * */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for( int i = digits.size() - 1; i >= 0; --i ) {
            digits[ i ] += carry;
            carry = digits[ i ] / 10;
            digits[ i ] %= 10;
        }

        if( carry )
            digits.insert( digits.begin(), carry );

        return digits;
    }
};
} // namespace V1

namespace V2 {
/*
 * We increase each value in digits from right ot left side, since less significant digit is on the right side.
 * If the current digit gets less or equal than 9, we return array from function, because we won't be anymore modify vector.
 * Otherwise assign zero, since in became 10.
 * After loop we know that current number should has format like this "10000....00", but now it's "00000...00"- one zero.
 * And we fix it, namely digit with index 0 assign 1, and push back addition value 0.
 *
 * N - length of the digits
 * Time (N), in case of all digits less than 9 it costs O(1)
 * Space (1), since we used only constant amount of space throughour algorithm
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for( int i = digits.size() - 1; i >= 0; --i ) {
            ++digits[ i ];
            if( digits[ i ] <= 9 )
                return digits;
            else
                digits[ i ] = 0;
        }

        digits[ 0 ] = 1;
        digits.push_back( 0 );

        return digits;
    }
};
} // namespace V2