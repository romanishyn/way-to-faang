/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

#pragma once

#include <vector>
#include <queue>
#include <algorithm>

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
 * We are gonna use Bread First Search. At each iteration we need to know how many nodes we have to process. The answer is
 * the current size of queue. Then we need to create a vector that will store value on the current level. Then we run loop and pull
 * nodes from current level, for each we take a value and push it to vector, and each child push to queue.
 * After loop add levelValues to result collection.
 *
 * Time (N), since each node visited only once
 * Space (N), auxiliary queue for traversing tree, plus result collection, it takes 2N, but 2 we drop
 * */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if( !root )
            return {};

        vector<vector<int>> result;

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            const int levelSize = queue.size(); // How many nodes do we have to process on this current iteration of this loop

            vector< int > levelValues;

            for( int i = 0; i < levelSize; ++i ) {
                auto node = queue.front();
                queue.pop();

                levelValues.push_back( node->val );

                if( node->left )
                    queue.push( node->left );
                if( node->right )
                    queue.push( node->right );
            }

            result.push_back( std::move( levelValues ) );
        }

        return result;
    }
};
} // namespace V1

namespace V2 {
/*
 * In this solution we implement Deep First Search. We helper function, call it dfs. This is recursion function.
 * Base case is when node is nullptr. If size of a result vector equal number of level, that mean we are first on this level
 * and need add "buffer" for current level to result. And get collection from result by level, level is index in collection,
 * and push back value of a current node. Then handle each node recursively, plus increase level.
 *
 * Time (N), since each node visited only once
 * Space (N), in the worst case of completely unbalanced tree.
 * */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs( result, root, 0 );
        return result;
    }

private:
    void dfs( vector<vector<int>>& result, TreeNode* node, int level ) {
        if( !node )
            return;

        if( result.size() == level )
            result.push_back( {} );

        result[ level ].push_back( node->val );

        dfs( result, node->left, level + 1 );
        dfs( result, node->right, level + 1 );
    }
};
} // namespace V2

