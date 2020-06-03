/*
https://leetcode.com/problems/invert-binary-tree/
*/

#pragma once

#include <stack>
#include <queue>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace V1 {
class Solution {
public:
    TreeNode * invertTree( TreeNode * root ) {
        if( !root )
            return root;

        invertTree( root->left );
        invertTree( root->right );

        std::swap( root->left, root->right );

        return root;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    TreeNode * invertTree( TreeNode * root ) {
        std::stack< TreeNode * > stack;
        stack.push( root );

        while( !stack.empty() ) {
            auto node = stack.top();
            stack.pop();

            if( !node )
                continue;

            std::swap( node->left, node->right );
            stack.push( node->left );
            stack.push( node->right );
        }

        return root;
    }
};
} // namespace V2


namespace V3 {
class Solution {
public:
    TreeNode * invertTree( TreeNode * root ) {
        if( !root )
            return root;

        std::stack< TreeNode * > stack;
        stack.push( root );

        while( !stack.empty() ) {
            auto node = stack.top();
            stack.pop();

            std::swap( node->left, node->right );

            if( node->left )
                stack.push( node->left );
            if( node->right )
                stack.push( node->right );
        }

        return root;
    }
};
} // namespace V3

namespace V4 {
class Solution {
public:
    TreeNode * invertTree( TreeNode * root ) {
        if( !root )
            return root;

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            auto node = queue.front();
            queue.pop();

            std::swap( node->left, node->right );

            if( node->left )
                queue.push( node->left );
            if( node->right )
                queue.push( node->right );
        }

        return root;
    }
};
}