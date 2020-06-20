/*
https://leetcode.com/problems/same-tree/
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
 * Solution based on DFS, traversal implement on stack data structure, one stack for each tree.
 * We traversal two tree simultaneously in the same manner, while both stacks are not empty.
 * At each iteration we check current nodes, if they don't satisfy condition return false, else continue explore trees.
 * At the end, that both stack are empty.
 *
 * Time (n)
 * Space (n)
 * */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack< TreeNode* > pStack;
        std::stack< TreeNode* > qStack;

        pStack.push( p );
        qStack.push( q );

        while( !pStack.empty() && !qStack.empty() ) {
            auto pNode = pStack.top();
            auto qNode = qStack.top();

            pStack.pop();
            qStack.pop();

            if( !check( pNode, qNode ) )
                return false;

            pushChildren( pStack, pNode );
            pushChildren( qStack, qNode );
        }

        return pStack.empty() && qStack.empty();
    }

private:
    bool check( const TreeNode* p, const TreeNode* q ) {
        if( !p&& !q)
            return true;
        if( !p|| !q)
            return false;
        if( p->val != q->val )
            return false;

        return true;
    }

    void pushChildren( std::stack< TreeNode* >& stack, const TreeNode* node ) const {
        stack.push( node->left );
        stack.push( node->right );
    }
};
} // namespace V1

namespace V2 {
/*
 * The simplest solution is to use recursion. Check if p and q are not NULL, and their values are equal.
 * If all check are OK, then do the same for the child nodes recursively.
 *
 * Time (n), where N is number of nodes in the tree, since one node we visit only once.
 * Space (n), O(logN) in the best case, when tree is balances, and O(N) when tree is completely unbalanced, to keep a recursion stack.
 * */
class Solution {
public:
    bool isSameTree( TreeNode * p, TreeNode * q ) {
        if( !p && !q )
            return true;
        if( !p || !q )
            return false;
        if( p->val != q->val )
            return false;

        return isSameTree( p->left, q->left ) && isSameTree( p->right, q->right );
    }
}; // namespace V2
}

namespace V3 {
/*
 * We are gonna travers trees using Breadth Fire Search. Start from root nodes and then at each iteration pop the current nodes
 * out of the queue. Then do checks:
 * p and q are NULL then just continue
 * either p or q are NULL, or valuers of this nodes are not equal return false.
 * If checks are OK, push the child nodes.
 *
 * Time (n), since each node visited only once
 * Space (n), O(logN) in the best case of completely balances tree and O(N) in the worst case of completely unbalances tree.
 * */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue< TreeNode* > queue;

        queue.push( p );
        queue.push( q );

        while( !queue.empty() ) {
            auto first = queue.front();
            queue.pop();

            auto second = queue.front();
            queue.pop();

            if( !first && !second )
                continue;
            if( !first || !second )
                return false;
            if( first->val != second->val )
                return false;

            queue.push( first->left );
            queue.push( second->left );
            queue.push( first->right );
            queue.push( second->right );
        }

        return true;
    }
};
} // namespace V3
