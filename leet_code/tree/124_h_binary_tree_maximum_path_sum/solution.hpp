/*
https://leetcode.com/problems/same-tree/
*/

#pragma once

#include <stack>
#include <queue>
#include <algorithm>

//using std::max;

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
 * Path is a straight line. In each node we should make a decision, if we connect leftPath and rightPath with value of node
 * is it maxSum so far?, if so, then update maxSum.
 * Helper function should return the best sum, and it should make sense for finding a better solution in previous level, and
 * that's why we return value not less than zero. For instance:
 *    1
 *      4
 *   -1  -5
 *
 * Time(N): since each node visited only once
 * Space(N): O(logN) in the best case of completely balanced tree , O(N) in the worst case of completely unbalanced tree
 * */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs( root );
        return m_maxPath;
    }

private:
    int dfs( TreeNode* node ) {
        if( !node )
            return 0;

        const int leftPath = dfs( node->left );
        const int rightPath = dfs( node->right );

        m_maxPath = std::max( m_maxPath, node->val + leftPath + rightPath );

        return std::max( 0, node->val + std::max( leftPath, rightPath ) );
    }

private:
    int m_maxPath = std::numeric_limits< int >::min();
};
} // namespace V1

