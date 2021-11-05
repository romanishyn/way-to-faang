/*
https://leetcode.com/problems/binary-search-tree-iterator/
*/

#include <stack>

namespace {
/*
N - number of nodes
H - height of a tree

Time O(1) hasNext - just check notNull and IsEmpty, next - each node we visit twice, next function we can call N times (no move than visit each node), since O(1) on avarage
Space O(H)
*/
  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class BSTIterator {
    std::stack< TreeNode* > m_stack;
    TreeNode* m_node;
public:
    BSTIterator(TreeNode* root)
    :   m_node{ root } {
        
    }

    /** @return the next smallest number */
    int next() {
        while( m_node ) {
            m_stack.push( m_node );
            m_node = m_node->left;
        }

        auto currNode = m_stack.top();
        m_stack.pop();

        m_node = currNode->right;

        return currNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ! m_stack.empty() || m_node;
    }
};
} // namespace

namespace {
  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class BSTIterator {
    std::stack< TreeNode* > m_stack;

    void addLeftNodes( TreeNode* node ) {
        while( node ) {
            m_stack.push( node );
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        addLeftNodes( root );
    }

    /** @return the next smallest number */
    int next() {
        auto node = m_stack.top();
        m_stack.pop();

        addLeftNodes( node->right );

        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ! m_stack.empty();
    }
};
} // namespace

namespace {
class BSTIterator {
    std::stack< TreeNode* > stack;

    void pullLeftNodes( TreeNode* node ) {
        while( node ) {
            stack.push( node );
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pullLeftNodes( root );
    }

    int next() {
        auto node = stack.top();
        stack.pop();

        pullLeftNodes( node->right );

        return node->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};
} // namespace

namespace {
/*
H - hight of tree
N - number of nodes

Time O(N)
On average next() and hasNext() are Time O(1)
Space O(H)
*/
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        fillStack(root);
    }
    
    int next() {
        auto node = stack.top();
        stack.pop();
        
        fillStack( node->right );
        
        return node->val;
    }
    
    bool hasNext() {
        return ! stack.empty();
    }
    
private:
    void fillStack(const TreeNode* node ) {
        while( node ) {
            stack.push( node );
            node = node->left;
        }
    }
private:
    std::stack< const TreeNode* > stack;
};
} // namespace