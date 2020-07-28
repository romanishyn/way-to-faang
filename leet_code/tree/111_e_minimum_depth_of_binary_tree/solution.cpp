/*
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * */

#include <queue>

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
 * To find the shortest path (min depth) we should use Breadth First Search
 * We are going traverse tree using two-level nested loop. Outer loop iterating over each level of tree, and
 * inner loop iterating each node within a single level.
 *
 * N - number of nodes;
 *
 * Time O(N)
 * Space O(N)
 * */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if( !root )
            return 0;

        int depth = 1;
        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            const int levelSize = queue.size();

            for( int i = 0; i < levelSize; ++i ) {
                auto node = queue.front();
                queue.pop();

                if( !node->left && !node->right )
                    return  depth;

                if( node->left )
                    queue.push( node->left );
                if( node->right )
                    queue.push( node->right );
            }
        }

        return depth;
    }
};
}