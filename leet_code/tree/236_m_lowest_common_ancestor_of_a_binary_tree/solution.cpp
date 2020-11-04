/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

namespace {
/*
Recursive Approach

N - number of nodes
H - height of tree

Time O(N)
Space O(H)
*/
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( ! root )
            return root;

        if( root->val == p->val || root->val == q->val )
            return root;

        auto left = lowestCommonAncestor( root->left, p, q );
        auto right = lowestCommonAncestor( root->right, p, q );

        if( left && right )
            return root;

        return left ? left : right;
    }
};
} // namespace

namespace {
/*
Iterative using paret pointers

N - number of nodes
H - height of tree

Time O(N)
Space O(H)
*/
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map< TreeNode*, TreeNode* > parents;
        parents.try_emplace( root, nullptr );

        std::stack< TreeNode* > todo;
        todo.push( root );

        while( ! parents.count( p ) || ! parents.count( q ) ) {
            auto node = todo.top();
            todo.pop();

            if( node->left ) {
                todo.push( node->left );
                parents.try_emplace( node->left, node );
            }
            if( node->right ) {
                todo.push( node->right );
                parents.try_emplace( node->right, node );
            }
        }

        std::unordered_set< TreeNode* > ansestors;
        while( p ) {
            ansestors.insert( p );
            p = parents[ p ];
        }

        while( ! ansestors.count( q ) ) {
            q = parents[ q ];
        }

        return q;
    }
};
} // namespace
