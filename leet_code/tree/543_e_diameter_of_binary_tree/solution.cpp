/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
*/
 // Definition for a binary tree node.
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
    int diameterOfBinaryTree(TreeNode* root) {
        if( ! root )
            return 0;
        
        int ans = 0;
        getMaxDepth( root, ans );
        return ans;
    }

    int getMaxDepth( const TreeNode* node, int & ans ) {
        if( ! node )
            return 0;

        int leftDepth = getMaxDepth( node->left, ans );
        int rightDepth = getMaxDepth( node->right, ans );

        ans = std::max( ans, leftDepth + rightDepth );

        return 1 + std::max( leftDepth, rightDepth );
    }
};
} // namespace

namespace {
/*
N - number of nodes

Time O(N)
Space O(H) or O(N)
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        getDepth( root, result );
        return result;
    }

private:
    int getDepth(TreeNode* node, int& result ) {
        if( ! node )
            return 0;
        
        const int left = getDepth( node->left, result );
        const int right = getDepth( node->right, result );
        
        result = std::max( result, left + right );
        
        return 1 + std::max( left, right );
    }
};
} // namespace