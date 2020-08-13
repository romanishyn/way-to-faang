/*
https://leetcode.com/problems/unique-binary-search-trees/
*/

namespace {
/*
Top-down approach

At each number of nodes, do call recursively for left part and right part for each root in current range (N),
multiply left and right results (Cartesian product) and add product to the answer

N - number of nodes

It might be incorrect
Time O(N^N), N branched and N is map height of recursion stack
Space O(N), height of recursion stack
*/
class Solution {
public:
    int numTrees(int n) {
        if( n <= 1 )
            return 1;

        int result = 0;

        for( int root = 1; root <= n; ++root )
            result += numTrees( root - 1 ) * numTrees( n - root );

        return result;
    }
};
} // namespace

namespace {
/*
DP bottom-up

N - number of nodes

Time O(N^2)
Space O(N)
*/
class Solution {
public:
    int numTrees(int n) {
        vector< int > dp( n + 1 );
        dp[ 0 ] = 1;
        dp[ 1 ] = 1;

        for( int nodes = 2; nodes <= n; ++nodes ) {
            for( int root = 1; root <= nodes; ++root ) {
                dp[ nodes ] += dp[ root - 1 ] * dp[ nodes - root ];
            }
        }

        return dp.back();
    }
};
} // namespace