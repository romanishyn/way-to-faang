/*
https://leetcode.com/problems/boundary-of-binary-tree/
*/

#include <vector>
#include <unordered_set>
#include <stack>

using std::vector;

namespace {

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if( ! root )
            return {};

        std::vector< int > result;
        if( ! isLeaf( root ) )
            result.push_back( root->val );

        collectLeftSide( root->left, result );
        collectLeafs( root, result );
        collectRightSize( root->right, result );

        return result;
    }

private:
    bool isLeaf( TreeNode* node ) {
        return node && ( ! node->left && ! node->right );
    }

    void collectLeftSide(
        TreeNode* node,
        std::vector< int >& result
    )
    {
        while( node && ! isLeaf( node ) ) {
            result.push_back( node->val );

            if( node->left )
                node = node->left;
            else
                node = node->right;
        }
    }

    void collectLeafs(
        TreeNode* node,
        std::vector< int >& result
    )
    {
        std::stack< TreeNode* > stack;
        stack.push( node );

        while( ! stack.empty() ) {
            auto currNode = stack.top();
            stack.pop();

            if( isLeaf( currNode ) )
                result.push_back( currNode->val );

            if( currNode->right )
                stack.push( currNode->right );
            if( currNode->left )
                stack.push( currNode->left );
        }
    }

    void collectRightSize(
        TreeNode* node,
        std::vector< int >& result
    )
    {
        std::stack< int > rightSide;

        while( node && ! isLeaf( node ) ) {
            rightSide.push( node->val );

            if( node->right )
                node = node->right;
            else
                node = node->left;
        }

        while( ! rightSide.empty() ) {
            auto nodeVal = rightSide.top();
            rightSide.pop();

            result.push_back( nodeVal );
        }
    }
};
} // namespace
