/*
 * https://leetcode.com/problems/inorder-successor-in-bst/
 * */

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

namespace V1 {
/*
 * If this tree is Binary Search Tree, we need use this property: each values from left-subtree is less, and each values from
 * right-subtree is greater than value of current node.
 * If we consider inorder traversal, hence if p has right subtree that means next successor is left most node from right subtree.
 * If node has no right subtree, successor might be parent.
 *
 * For second scenario: we are trying to find successor from root node, and if root greater than p, then remember this node like possible successor,
 * and proceed considering left subtree. Otherwise consider right subtree.
 *
 * Time (H)
 * Space (1)
 * */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if( p->right ) {
            auto node = p->right;
            while( node->left )
                node = node->left;
            return node;
        }

        TreeNode* successor = nullptr;
        while( root ) {
            if( root->val > p->val ) {
                successor = root;
                root = root->left;
            }
            else
                root = root->right;
        }

        return successor;
    }
};
} // namespace V1

// TODO: recursive approach: https://leetcode.com/problems/inorder-successor-in-bst/discuss/72653/Share-my-Java-recursive-solution
namespace V2 {
/*
 * The same approach like described above, but recursive.
 * */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return nullptr;
    }
};
} // namespace V2