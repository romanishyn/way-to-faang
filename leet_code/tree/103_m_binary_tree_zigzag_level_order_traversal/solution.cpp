/*
 *https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
 * Idea based on DFS. Traverse tree, and value of node push to the result with corresponding index, index is current level of tree.
 * To know current level of will push onto the space pair of values <node, level>.
 * Also when we are going to push value to the result, need to check if the size of the result equals level, if so then push back empty collection.
 * When we add push node onto the stack, first have to go right child.
 * After traversing we will reverse collection with add indices;
 *
 * N - number of nodes
 *
 * Time O(N), since we need traverse all tree
 * Space O(N), need store values of all nodes, if we are ignoring output result, then O(logN) in case of completely balanced tree,
 * and O(N) in case completely unbalanced tree
 * */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if( !root )
            return result;

        std::stack< std::pair< TreeNode*, int > > s;
        s.emplace( root, 0 );

        while( !s.empty() ) {
            auto [ node, level ] = s.top();
            s.pop();

            if( result.size() == level )
                result.push_back( {} );

            result[ level ].push_back( node->val );

            if( node->right )
                s.emplace( node->right, level + 1 );
            if( node->left )
                s.emplace( node->left, level + 1 );
        }

        for( int i = 1; i < result.size(); ++i ) {
            if( i & 1 )
                reverse( result[ i ] );
        }

        return result;
    }

private:
    void reverse( vector< int >& collection ) {
        const int size = collection.size();
        for( int i = 0; i < size / 2; ++i ) {
            std::swap( collection[ i ], collection[ size - i - 1 ] );
        }
    }
};
} // namespace V1

namespace V2 {
/*
 * Use BFS. To traverse tree we are going to use two-level nested loop, the outer loop iterating each level of tree,
 * and inner loop iterating each one within a single level.
 *
 * N - number of nodes
 * Time O(N), need visit all nodes
 * Space O(N), in the case of completely balanced tree, size of level that contains the most nodes equal roughly N/2
 * */
}