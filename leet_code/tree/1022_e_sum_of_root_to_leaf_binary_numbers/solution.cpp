/*
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
*/

#include <stack>

namespace {
/*
Recursive preorder traversal

N - number of nodes

Time O(N)
Space O(H)
*/
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if( ! root )
            return 0;

        int totalSum = 0;

        std::stack< std::pair< TreeNode*, int > > todo;
        todo.emplace( root, 0 );

        while( ! todo.empty() ) {
            auto [node, path] = todo.top();
            todo.pop();

            path = ( path << 1 ) | node->val;

            if( isLeaf( node ) ) {
                totalSum += path;
            }
            else {
                if( node->left ) {
                    todo.emplace( node->left, path );
                }
                if( node->right ) {
                    todo.emplace( node->right, path );
                }
            }
        }

        return totalSum;
    }

private:
    bool isLeaf( const TreeNode* node ) const {
        return ! node->left && ! node->right;
    }
};
} // namespace