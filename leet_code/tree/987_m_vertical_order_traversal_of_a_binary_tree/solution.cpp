/*
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * */
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
    
  //Definition for a binary tree node.
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
 * Collect all nodes using DFS inorderd traversal (might be any traversal)
 * Sort using tree criteria <col_idx, row_idx, node_val>
 * Sort criteria:
 * Most left column should go first;
 * Node closer to root has more priority to node with the same col_idx
 * If col_idx and row_idx are equal, then sort in ascending order by value
 *
 * N - number of nodes
 *
 * Time O(NlogN), need sort all nodes
 * Space (N)
 * */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if( !root )
            return {};

        std::map< int/*col_idx*/, std::map< int/*row_idx*/, std::vector< int > > > nodes;
        std::stack< std::tuple< TreeNode*, int/*row_idx*/, int/*col_idx*/ > > todo;
        todo.emplace( root, 0, 0 );

        while( !todo.empty() ) {
            auto [node, rowIdx, colIdx] = todo.top();
            todo.pop();

            nodes[ colIdx ][ rowIdx ].push_back( node->val );

            if( node->right )
                todo.emplace( node->right, rowIdx + 1, colIdx + 1 );
            if( node->left )
                todo.emplace( node->left, rowIdx + 1, colIdx - 1 );
        }

        vector<vector<int>> result;
        for( auto& [_,rowIdx_values]: nodes ) {
            vector< int > vals;
            for( auto& [_, values]: rowIdx_values ) {
                std::sort( values.begin(), values.end() );
                vals.insert( vals.end(), values.begin(), values.end() );
            }
            result.push_back( std::move( vals ) );
        }
        
        return result;
    }
};
} // namespace V1 

namespace {
/*
 * N - number of nodes
 *
 * Time O(NlogN), need sort all nodes
 * Space (N)
*/
class Solution {
    using TreeModel = std::map< int, std::map< int, std::multiset< int > > >;
    
    TreeModel buildTreeModel( const TreeNode* root ) {
        TreeModel model;
             
        std::stack< std::tuple< const TreeNode*, int/*row*/, int/*col*/ > > stack;
        stack.emplace( root, 0, 0 );
        
        while( ! stack.empty() ) {
            auto [node, row, col] = stack.top();
            stack.pop();
            
            model[ col ][ row ].insert( node->val );
            
            if( node->left )
                stack.emplace( node->left, row + 1, col - 1 );
            if( node->right )
                stack.emplace( node->right, row + 1, col + 1 );
        }
        
        return model;
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        auto treeModel = buildTreeModel( root );
        
        std::vector< std::vector< int > > result;
        
        for( const auto& [_, col] : treeModel ) {
            std::vector< int > temp;
            
            for( const auto& [_2, row] : col ) {
                std::copy( row.begin(), row.end(), std::back_inserter( temp ) );
            }
            
            result.push_back( std::move( temp ) );
        }
        
        return result;
    }
};
} // namespace


