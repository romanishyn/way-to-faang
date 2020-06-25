/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
 * To find LCA we can use property of BST: all values from left subtree are less than node value and all values from
 * right subtree are greater than node value.
 * 1) Start from root node and check
 * 2) if pValue and qValue are less than current value, that means LCA is on left side, and we need check left subtree, go back to step 1
 * 3) if pValue and qValue are greater than current value, that mean
 * 4) if 2 and 3 steps are not true, this mean we have hound the node which is common to p's and q's subtrees.
 *    and hence we return this common node as the LCA.
 *
 * Time (N), where N is the number of nodes in the tree. In the worst case we might be visiting all the nodes of BST
 * Space (H), where H is the height of tree, O(logN) in case of completely balanced tree, O(N) in case of completely unbalanced tree. (in case of skewed BST)
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root )
            return nullptr;

        if( p->val < root->val && q->val < root->val )
            return lowestCommonAncestor( root->left, p, q );
        if( p->val > root->val && q->val > root->val )
            return lowestCommonAncestor( root->right, p, q );

        return root;
    }
};
} // namespace V1

namespace V2 {
/*
 * The idea and steps described above. The difference is that, we can implement it without any stack (recursion or data structure),
 * traverse down the tree iteratively, since we don't need to backtrace, we need find split node. The point where p and q
 * won't be part of the same subtree or when one is the parent of the other.
 *
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while( root ) {
            if( p->val < root->val && q->val < root->val )
                root = root->left;
            else if( p->val > root->val && q->val > root->val )
                root = root->right;
            else
                return root;
        }

        return root;
    }
};
} // namespace V2

