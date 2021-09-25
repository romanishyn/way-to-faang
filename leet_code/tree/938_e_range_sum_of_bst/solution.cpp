/*
 * https://leetcode.com/problems/range-sum-of-bst/
 */

#include <stack>

namespace {
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) {}

    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}

    TreeNode( int x, TreeNode * left, TreeNode * right ) : val( x ), left( left ), right( right ) {}
};
}

namespace V1 {
/*
 * Here we use iterative inorder traversal (we can use any iterative traversal), start from root node.
 * At each node we check if value of this node is in range of given boundris, if so add current value to result, else
 * continue traverse tree. In the and return result.
 *
 * N - count of nodes
 * H - height of tree
 * Time (N), or 2^H
 * Space (H), O(NlogN) in case of completely balances tree, and O(N) in case of completely unbalanced tree, so H include both meaning
 * */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;

        std::stack< TreeNode* > stack;

        while( !stack.empty() || root ) {
            while( root ) {
                stack.push( root );
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if( L <= root->val && root->val <= R )
                sum += root->val;

            root = root->right;
        }

        return sum;
    }
};
} // namespace V1

namespace {
/*
N - number of nodes

Time O(N)
Space O(H)
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if( ! root )
            return 0;
        
        int result = 0;
        
        if( low <= root->val && root->val <= high )
            result += root->val;
        
        result += rangeSumBST( root->left, low, high );
        result += rangeSumBST( root->right, low, high );
        
        return result;
    }
};
}
