/*
 * https://leetcode.com/problems/binary-tree-right-side-view/
 * */

#include <vector>
#include <stack>

using std::vector;

//  Definition for a binary tree node.
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
 * Using iterative DFS, we start visiting nodes from right side, if it first time on current level, end value of this node to the result.
 *
 * N - number of nodes
 *
 * Time O(N)
 * Space O(N)
 * */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if( !root )
            return {};

        std::stack< std::pair< TreeNode*, int > > stack;
        stack.emplace( root, 0 );

        vector< int > result;

        while( !stack.empty() ) {
            auto [ node, level] = stack.top();
            stack.pop();

            if( result.size() == level )
                result.push_back( node->val );

            if( node->left )
                stack.emplace( node->left, level + 1 );
            if( node->right )
                stack.emplace( node->right, level + 1 );
        }

        return result;
    }
};
} // namespace V1