/*
https://leetcode.com/problems/subtree-of-another-tree/
*/

#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>

using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Good explanation about this problem: https://leetcode.com/problems/subtree-of-another-tree/discuss/102724/Java-Solution-tree-traversal/153500
 *
 * NOTE: TIME COMPLEXITY:
 *  Recursion stack space is dictated by the height of S. Even if T is the bigger tree, S has no clue.
 *  S will keep checking till its max depth. The identicality check will terminate with the shorter S height anyway.
 *  So, the recursion stack goes as deep as S's height. O(logs) avg case & O(s) for skewed.
 * */

namespace V1 {
/*
 * For each node during pre-order traversal of s, use a recursion function isSame to validate if sub-tree started from this
 * node is the same tree t
 *
 * Where n is number of nodes in s, m is number of nodes in t
 *
 * Time (n*m),
 * Space (n)
 * */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if( !s )
            return false;

        if( isSame( s, t ) )
            return true;

        return isSubtree( s->left, t ) || isSubtree( s->right, t );
    }

private:
    bool isSame( TreeNode* s, TreeNode* t ) {
        if( !s && !t )
            return true;
        if( !s || !t )
            return false;
        if( s->val != t->val )
            return false;

        return isSame( s->left, t->left ) && isSame( s->right, t->right );
    }
};
} // namespace V1

namespace V2 {
/*
 * Use DFS for traversing trees s and t.
 * 1. Start from a node of tree s (lets called this s-node)
 * 2. Compare the trees forming from s-node and root node t
 * 3. If the trees are the same (LC problem #100) then return true
 * 4. Else go to step one and check for left and right children of s-node
 *
 * Where n is number of nodes in s, m is number of nodes in t
 * Time (n*m)
 * Space (n)
 * */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        std::stack< TreeNode* > sStack;
        sStack.push( s );

        while( !sStack.empty() ) {
            auto node = sStack.top();
            sStack.pop();

            if( node->val == t->val && isSubtreeEqual( node, t ) )
                return true;

            if( node->left )
                sStack.push( node->left );
            if( node->right )
                sStack.push( node->right );
        }

        return false;
    }

private:
    bool isSubtreeEqual( TreeNode* s, TreeNode* t ) {
        std::stack< TreeNode* > sStack;
        std::stack< TreeNode* > tStack;

        sStack.push( s );
        tStack.push( t );

        while( !sStack.empty() && !tStack.empty() ) {
            auto node1 = sStack.top();
            auto node2 = tStack.top();

            sStack.pop();
            tStack.pop();

            if( !node1 && !node2 )
                continue;

            if( !node1 || !node2 )
                return false;
            if( node1->val != node2->val )
                return false;

            pushChildren( sStack, node1 );
            pushChildren( tStack, node2 );
        }

        return sStack.empty() && tStack.empty();
    }

    void pushChildren( std::stack< TreeNode* >& stack, TreeNode* root ) {
        stack.push( root->left );
        stack.push( root->right );
    }
};
} // namespace V2

