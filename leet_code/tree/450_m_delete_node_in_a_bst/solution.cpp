/*
https://leetcode.com/problems/delete-node-in-a-bst/
*/

#include <unordered_map>

namespace {
/*
case 1: node is leaf
case 2: node has only one child
case 3: node has two children

N - number of nodes

Time O(H) - log(N) in case of balances tree, or N in case of comletely unbalanced tree
Space O(H)
*/
  //Definition for a binary tree node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( ! root )
            return root;

        if( root->val < key ) {
            root->right = deleteNode( root->right, key );
        }
        else if( root->val > key ) {
            root->left = deleteNode( root->left, key );
        }
        else {
            if( ! root->left && ! root->right ) {
                delete root;
                root = nullptr;
            }
            else if( ! root->left || ! root->right ) {
                auto temp = root->right ? root->right : root->left;
                delete root;
                root = temp;
            }
            else {
                auto minNode = findMin( root->right );
                root->val = minNode->val;
                root->right = deleteNode( root->right, minNode->val );
            }
        }

        return root;
    }

private:
    TreeNode* findMin( TreeNode* node ) {
        while( node && node->left ) {
            node = node->left;
        }
        return node;
    }
};
} // namespace
