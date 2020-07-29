/*
 * https://leetcode.com/problems/path-sum/
 * */

#include <stack>

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

namespace V1 {
/*
 * We are using recursive DFS approach. At each call we extract value of current from target sum, and pass this value further.
 * If current node is leaf, check if sum minus node's value equals zero, if so, return true, else false.
 * If current node is not leaf, continue traversing children nodes, with new value of sum: sum - currVal
 *
 * N - total number of nodes
 *
 * Time O(N) - we are visiting all nodes
 * Space O(H) - O(logN) in case of completely balanced tree, and O(N) in case of completely unbalanced tree
 * */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if( !root )
            return false;
        if( !root->left && !root->right ) {
            return ( sum - root->val ) == 0;
        }

        return hasPathSum( root->left, sum - root->val ) || hasPathSum( root->right, sum - root->val );
    }
};
} // namespace V1

namespace V2 {
/*
 * The base idea is iterative preorder DFS. We need remeber current sum for each node, and when we come across leaf
 * node check following condition: if sum - currNodeVal equals zero, return true, else continue traversing.
 *
 * N - number of nodes
 *
 * Time (N)
 * Space (H)
 * */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if( !root )
            return false;

        std::stack< std::pair< TreeNode*, int > > stack;
        stack.emplace( root, sum );

        while( !stack.empty() ) {
            auto [ node, currSum ] = stack.top();
            stack.pop();

            if( isLeaf( node ) && ( currSum - node->val ) == 0 ) {
                return true;
            }

            if( node->left )
                stack.emplace( node->left, currSum - node->val );
            if( node->right )
                stack.emplace( node->right, currSum - node->val );
        }

        return false;
    }

private:
    bool isLeaf( TreeNode* node ) {
        return !node->left && !node->right;
    }
};
} // namespace V2
