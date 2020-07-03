/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/

#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using std::vector;


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
 * The idea is using a Breadth Fists Search, in the end of function reverse result;
 * We need create queue and push root node if it is not null, else return empty result.
 * Keep processing nodes until queue is empty. In the begin of each iteration we get size of queue, this value is
 * count of node on current level of tree, then we start for loop from 0 to levelSize and pull nodes from queue and add
 * value of current node to vector (levelValues), and add to queue left and right children if they are not null.
 * In the end reverse result collection and return final result;
 *
 * N - total number of nodes
 * H - height of tree
 *
 * Time (N), visit each node once
 * Space (H), O(logN) in case of completely balanced tree, O(N) in case of skewed tree, when each level has only one node.
 *            So height include both meaning
 * */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if( !root )
            return result;

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            const std::size_t levelSize = queue.size();
            std::vector< int > levelValues( levelSize );

            for( std::size_t i = 0; i < levelSize; ++i ) {
                auto node = queue.front();
                queue.pop();

                levelValues[ i ] = node->val;

                if( node->left )
                    queue.push( node->left );
                if( node->right )
                    queue.push( node->right );
            }

            result.push_back( std::move( levelValues ) );
        }

        std::reverse( result.begin(), result.end() );

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * The base idea is using recursive Depth First Search, and calculating the depth of tree beforehand.
 * If we don't want to calculate depth, we need reverse result collection after dfs;
 *        3
 *      /   \
 *     2    4
 *         /  \
 *        6   7
 *
 * N - count of nodes
 * H - height of tree
 *
 * Time (N)
 * Space (H), O(logN) in case completely balances tree, and O(N) in case of generate linked list
 * */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        NodeValues result( getDepth( root ) );

        dfs( root, result, 0 );

        return result;
    }

private:
    using NodeValues = std::vector< std::vector< int > >;

private:
    void dfs( TreeNode* node, NodeValues& values, int level ) {
        if( !node )
            return;

        values[ values.size() - level - 1 ].push_back( node->val );

        dfs( node->left, values, level + 1 );
        dfs( node->right, values, level + 1 );
    }

    int getDepth( TreeNode* node ) {
        if( !node )
            return 0;

        return 1 + std::max( getDepth( node->left ), getDepth( node->right ) );
    }
};
} // namespace V2

namespace V3 {
/*
 * Iterative Depth First Search + calculating depth
 *
 * N - number of nodes
 * H - height of tree
 *
 * Time (N)
 * Space (H)
 * */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if( !root )
            return {};

        NodeValues result( getDepth( root ) );

        std::stack< std::pair< TreeNode*, int > > stack;
        stack.emplace( root, 0 );

        while( !stack.empty() ) {
            auto [node, depth ] = stack.top();
            stack.pop();

            result[ result.size() - depth - 1 ].push_back( node->val );

            if( node->right )
                stack.emplace( node->right, depth + 1 );
            if( node->left )
                stack.emplace( node->left, depth + 1 );
        }

        return result;
    }

private:
    using NodeValues = std::vector< std::vector< int > >;

    int getDepth( TreeNode* root ) const {
        if( !root )
            return 0;

        std::stack< std::pair< TreeNode*, int > > stack;
        stack.emplace( root, 1 );

        int maxDepth = 0;

        while( !stack.empty() ) {
            auto [node, depth] = stack.top();
            stack.pop();

            maxDepth = std::max( maxDepth, depth );

            if( node->left )
                stack.emplace( node->left, depth + 1 );
            if( node->right )
                stack.emplace( node->right, depth + 1 );
        }

        return maxDepth;
    }
};
} // namespace V3
