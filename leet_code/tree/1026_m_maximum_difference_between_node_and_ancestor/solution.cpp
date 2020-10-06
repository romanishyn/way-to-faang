/*
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
*/

namespace {
/*
Recurison Preorder DFS

N - number of nodes

Time O(N)
Space O(N)
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
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff( root, root->val, root->val );
    }

private:
    int maxAncestorDiff( TreeNode* node, int minVal, int maxVal ) {
        if( ! node )
            return maxVal - minVal;

        minVal = std::min( minVal, node->val );
        maxVal = std::max( maxVal, node->val );

        return std::max(
                maxAncestorDiff( node->left, minVal, maxVal )
            ,   maxAncestorDiff( node->right, minVal, maxVal )
            );
    }
};
} // namespace

namespace {

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
    int maxAncestorDiff(TreeNode* root) {
        std::stack< std::tuple< TreeNode*, int/*minVal*/, int/*maxVal*/ > > todo;
        todo.emplace( root, root->val, root->val );

        int maxDiff = 0;

        while( ! todo.empty() ) {
            auto [node, minVal, maxVal] = todo.top();
            todo.pop();

            minVal = std::min( minVal, node->val );
            maxVal = std::max( maxVal, node->val );

            maxDiff = std::max( maxDiff, maxVal - minVal );

            if( node->left )
                todo.emplace( node->left, minVal, maxVal );
            if( node->right )
                todo.emplace( node->right, minVal, maxVal );
        }

        return maxDiff;
    }
};
} // namespace
