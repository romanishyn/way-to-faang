/*
 * LeetCode: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 *


 1) We should know that equal number of opening and closing bracket is not enough to solve this problem

 Hints:
 2) Let's (Try to) consider the difference between prefixes of matching bracket strings to the non-matching ones.
    (()
    (())
    (()))

 )(

 (((((
 )))))

 3) Note that in every prefix the number of opening bracket is equal or greater than the number of opening bracket
 4) Try to walk through example and USE COUNTER in order to count the difference between
    the number of '(' and ')' for each prefix:
    4.1 every time the counter goes below zero, the current prefix has more open brackets than close brackets, then
        increment the counter by 1, since we must add an additional open brackets to the beginning of the string
        in order to correct the brackets.
    4.2 At the end of the string, if we have found more open than close, we need to add additional close to
        the end of the string. Namely we need to add extra opening brackets to the counter.

 5) What does balanced string mean?
 Keep track of the balance of the string: the number of '(''s minus the number of ')''s.
 A string is valid if its balance is 0, plus every prefix has non-negative balance.

     Let's walk through example together,
----------------------------------------------------------
  ### LeetCode Solution

  class Solution {
    public int minAddToMakeValid(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            bal += S.charAt(i) == '(' ? 1 : -1;
            // It is guaranteed bal >= -1
            if (bal == -1) {
                ans++;
                bal++;
            }
        }

        return ans + bal;
    }
}
----------------------------------------------------------
  ## My solution
  int bracketMatch( const string& text )
 {
  int leftBrackets = 0;

  int result = 0;

  for( int i = 0; i < text.size(); ++i ) {
    if( text[ i ] == '(' )
      ++leftBrackets;
    else if( leftBrackets == 0 )
      ++result;
    else
      --leftBrackets;
  }

  return result + leftBrackets;
 }
----------------------------------------------------------


 */