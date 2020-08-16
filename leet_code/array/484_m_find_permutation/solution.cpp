/*
https://leetcode.com/problems/find-permutation/
*/

#include <vector>
#inlude <stack>
#include <string>

using std::string;
using std::vector;

namespace {
/*
N - length of s + 1

Time O(N), N numbers will be pushed and poped from stack
Space O(N), stack can grow up to N in the worst case
*/
class Solution {
public:
    vector<int> findPermutation(string s) {
        std::vector< int > result;
        std::stack< int > stack;

        // Do not handle last posible digit of permutation in loop
        for( int i = 1; i <= s.size(); ++i ) {
            if( s[ i - 1 ] == 'I' ) {
                stack.push( i );
                while( !stack.empty() ) {
                    result.push_back( stack.top() );
                    stack.pop();
                }
            }
            else {
                stack.push( i );
            }
        }

        stack.push( s.size() + 1 );
        while( !stack.empty() ) {
            result.push_back( stack.top() );
            stack.pop();
        }

        return result;
    }
};
} // namespace

namespace {
// TODO: Space O(N)
} // namespace