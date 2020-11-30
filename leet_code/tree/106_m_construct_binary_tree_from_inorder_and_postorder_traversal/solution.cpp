/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::unordered_map< int, int > valToIdx;
        for( int i = 0; i < inorder.size(); ++i )
            valToIdx[ inorder[ i ] ] = i;

        int postIdx = postorder.size() - 1;
        return builTree( inorder, 0, inorder.size() - 1, postorder, postIdx, valToIdx );
    }

private:
    TreeNode* builTree( const vector<int>& inorder, int left, int right, const vector<int>& postorder, int& postIdx, const std::unordered_map< int, int >& valToIdx ) {
        if( left > right )
            return nullptr;

        auto node = new TreeNode( postorder[ postIdx ] );
        --postIdx;
        int pos = valToIdx.at( node->val );
        node->right = builTree( inorder, pos + 1, right, postorder, postIdx, valToIdx );
        node->left = builTree( inorder, left, pos - 1, postorder, postIdx, valToIdx );

        return node;
    }
};
} // namespace
