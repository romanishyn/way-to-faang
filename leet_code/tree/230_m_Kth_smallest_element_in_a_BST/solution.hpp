/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

#pragma once

#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

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
 * To solve the problem, one could use the property of BST: inorder traversal of BST is an array sorted in ascending order.
 * At each node we decrease k and check if it is 0, if so return current value and stop traversal;
 *
 * Time (h + k), h is height of tree
 * Space (h) h is height of tree
 * */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestNode( root, k )->val;
    }

private:
    TreeNode* kthSmallestNode( TreeNode* node, int& k ) {
        if( !node )
            return nullptr;

        if( auto n = kthSmallestNode( node->left, k ) )
            return n;

        --k;
        if( k == 0 )
            return node;

        if( auto n = kthSmallestNode( node->right, k ) )
            return n;

        return nullptr;
    }
};
} // namespace V1

namespace V2 {
/*
 * We will use iterative inorder BST traversal. Since property of inorder traversal is nodes traverse in ascending order.
 * At each node, we decrement k and check if it becomes zero if a condition is true return current value, else continue traversing the tree.
 *
 * Time (h + k) since before we starting pop out node from a stack we have to go down to a leaf. Then continue traversing a tree until k is zero.
 * Space (h) O(n) in the worst case, O(logn) in the average case
 * */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack< TreeNode* > stack;

        while( !stack.empty() || root ) {
            while( root ) {
                stack.push( root );
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            --k;
            if( k == 0 )
                return root->val;

            root = root->right;
        }

        return 0;
    }
};
} // namespace V2

