/*
https://leetcode.com/problems/invert-binary-tree/
*/

#pragma once

#include <stack>
#include <queue>
#include <algorithm>

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
 * Base case: if node does not exist, then return zero. Otherwise get depths of each subtree,
 * choose bigger value and add 1 (1 it's plus current level)
 *
 * Time (n)
 * Space (n)
 * */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if( !root )
            return 0;

        return 1 + std::max( maxDepth( root->left ), maxDepth( root->right ) );
    }
};
} // namespace V1

namespace V2 {
/*
 * It level-order traversal (BFS). Each iteration in while loop it's a new level in tree, it allow us to increment counter of depth
 * and also we should process all nodes on current level.
 * So we need know how many nodes on current level, and this information we get from queue. Size of queue is count of
 * nodes on current level. And we do it while queue is not empty. In the end, return max depth.
 *
 * Time (n)
 * Space (n)
 * */
class Solution {
public:
    int maxDepth( TreeNode * root ) {
        if( !root )
            return 0;

        std::queue< TreeNode * > queue;
        queue.push( root );

        int depth = 0;

        while( !queue.empty() ) {
            ++depth;

            for( int i = queue.size(); i > 0; --i ) {
                auto node = queue.front();
                queue.pop();

                if( node->left )
                    queue.push( node->left );
                if( node->right )
                    queue.push( node->right );
            }
        }

        return depth;
    }
};
} // namespace V2


namespace V3 {
/*
 * In this solution instead of call stack we use own stack (data structure). To get depth on each level we need use
 * addition stack which will keep tracking of current position. We implement simple DFS, and for each next level we
 * increment count depth.
 * Right child push first to save traverse tree in the same fashion like stack recursion. But actually it doesn't matter.
 *
 * Time (n)
 * Space (2n) -> (n)
 * */
class Solution {
public:
    int maxDepth( TreeNode * root ) {
        std::stack< TreeNode * > stack;
        std::stack< int > depths;

        stack.push( root );
        depths.push( 1 );

        int depth = 0;

        while( !stack.empty() ) {
            auto node = stack.top();
            stack.pop();

            int currDepth = depths.top();
            depths.pop();

            if( node ) {
                depth = std::max( depth, currDepth );

                stack.push( node->right );
                depths.push( currDepth + 1 );

                stack.push( node->left );
                depths.push( currDepth + 1 );
            }
        }

        return depth;
    }
};
} // namespace V3
