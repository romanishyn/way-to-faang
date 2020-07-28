/*
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/
 * */

#include <vector>
#include <queue>

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
 * We are going to use BFS. To travers tree we are using two-level nested loop. Outer loop iterate over each level,
 * and inner loop over each node within single level.
 * To count average value, we are going to accumulate all value on each level and divide by size of level, after that
 * push value to result vector.
 *
 * N - number of nodes
 *
 * Time O(N) - we need to visit all nodes
 * Space O(N) - in case of completely balances tree lowest level contains all leaf nodes, number of those nodes equals N/2
 * */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if( !root )
            return {};

        std::vector< double > result;

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            const int levelSize = queue.size();

            double levelValuesSum = 0;
            for( int i = 0; i < levelSize; ++i ) {
                auto node = queue.front();
                queue.pop();

                levelValuesSum += node->val;
                if( node->left )
                    queue.push( node->left );
                if( node->right )
                    queue.push( node->right );
            }

            result.push_back( levelValuesSum / levelSize );
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * Depth First Search approach
 *
 * N - number of nodes
 *
 * Time O(N)
 * Space (H), it equals either O(logN) or O(N)
 * */
class Solution {
public:
    using NodesInfo = std::vector< std::pair< double, int > >;

    vector<double> averageOfLevels(TreeNode* root) {
        NodesInfo nodesInfo;
        dfs( nodesInfo, root, 0 );

        vector<double> result;
        for( auto [sum, count]: nodesInfo ) {
            result.push_back( sum / count );
        }

        return result;
    }

    void dfs( NodesInfo& nodesInfo, TreeNode* node, int level ) {
        if( !node )
            return;

        if( level == nodesInfo.size() ) {
            nodesInfo.emplace_back( node->val, 1 );
        }
        else {
            auto& [ sum, count ] = nodesInfo[ level ];
            sum += node->val;
            ++count;
        }

        dfs( nodesInfo, node->left, level + 1 );
        dfs( nodesInfo, node->right, level + 1 );
    }
};
} // namespace V2