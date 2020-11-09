/*
https://leetcode.com/problems/maximum-average-subtree/
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
    double maximumAverageSubtree(TreeNode* root) {
        double result{ -1 };
        maximumAverageSubtree( root, result );
        return result;
    }

private:
    std::pair< int, int > maximumAverageSubtree( TreeNode* node, double& result ) {
        if( ! node )
            return { 0, 0 };

        auto [leftSum, leftCount] = maximumAverageSubtree( node->left, result );
        auto [rightSum, rightCount] = maximumAverageSubtree( node->right, result );

        int currSum = leftSum + rightSum + node->val;
        int currCount = leftCount + rightCount + 1;

        result = std::max( result, static_cast< double >( currSum ) / currCount );

        return { currSum, currCount };
    }
};
} // namespace
