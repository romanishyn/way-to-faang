/*
https://leetcode.com/problems/merge-two-binary-trees/
*/

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( ! t1 && ! t2 )
            return nullptr;

        const int val1 = t1 ? t1->val : 0;
        const int val2 = t2 ? t2->val : 0;

        auto node = new TreeNode( val1 + val2 );
        node->left = mergeTrees( t1 ? t1->left : nullptr, t2 ? t2->left : nullptr );
        node->right = mergeTrees( t1 ? t1->right : nullptr, t2 ? t2->right : nullptr );

        return node;
    }
};
} // namespace

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if( ! t1 && ! t2 )
            return nullptr;

        const int val1 = t1 ? t1->val : 0;
        const int val2 = t2 ? t2->val : 0;

        auto node = new TreeNode( val1 + val2 );
        node->left = mergeTrees( t1 ? t1->left : nullptr, t2 ? t2->left : nullptr );
        node->right = mergeTrees( t1 ? t1->right : nullptr, t2 ? t2->right : nullptr );

        return node;
    }
};
} // namespace