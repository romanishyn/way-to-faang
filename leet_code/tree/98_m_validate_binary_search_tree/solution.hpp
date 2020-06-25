/*
https://leetcode.com/problems/validate-binary-search-tree/
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
 * If traverse valid BST in inorder traversal, each new node must be greater than previous one.
 * So we can collect all values and check if our vector sorted in ascending order.
 *
 * n is total count of nodes.
 * Time (n)
 * Space (n), we store all nodes in vector
 * */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector< int > values;
        inorderTraverse( root, values );

        for( int i = 1; i < values.size(); ++i ) {
            if( values[ i - 1] >= values[ i ] )
                return false;
        }

        return true;
    }

private:
    void inorderTraverse( TreeNode* node, std::vector< int >& values ) {
        if( !node )
            return;

        inorderTraverse( node->left, values );
        values.push_back( node->val );
        inorderTraverse( node->right, values );
    }
};
} // namespace V1

namespace V2 {
/*
 * Here we use iterative inorder traversal. If previous node is not null and previous value less than current, we continue
 * traversing all tree. If happens that condition is not OK, return false.
 * For previous value we will use previous node, initial value is null
 *
 * NOTE: possible value for valNode is std::numeric_limits<int>::min()
 *
 * Time (n), we visit each node once, if BST is valid, otherwise less than n
 * Space (h), h is height of tree, h is O(logN) in case of completely balanced tree, and O(n) in case of completely unbalanced tree
 * */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::stack< TreeNode* > stack;
        TreeNode* prevNode = nullptr;

        while( !stack.empty() || root ) {
            while( root ) {
                stack.push( root );
                root = root->left;
            }

            root = stack.top();
            stack.pop();

            if( prevNode && prevNode->val >= root->val )
                return false;

            prevNode = root;
            root = root->right;
        }

        return true;
    }
};
} // namespace V2

namespace V3 {
/*
 * Here we use the same approach like above, but instead of own stack structure we use recursion stack
 *
 * NOTE:
 *   - possible value for valNode is std::numeric_limits<int>::min()
 *   - type of second argument of inorderTravers is *&
 *
 * Time (n), we visit each node once, if BST is valid, otherwise less than n
 * Space (h), h is height of tree, h is O(logN) in case of completely balanced tree, and O(n) in case of completely unbalanced tree
 * */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prevNode = nullptr;
        return inorderTravers( root, prevNode );
    }

private:
    bool inorderTravers(TreeNode* node, TreeNode*& prevNode ) {
        if( !node )
            return true;

        if( !inorderTravers( node->left, prevNode ) )
            return false;

        if( prevNode && prevNode->val >= node->val )
            return false;

        prevNode = node;

        if( !inorderTravers( node->right, prevNode ) )
            return false;

        return true;
    }
};
} // namespace V3
