/*
 * https://leetcode.com/problems/binary-tree-right-side-view/
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
 * Using iterative DFS, we start visiting nodes from right side, if it first time on current level, end value of this node to the result.
 *
 * N - number of nodes
 *
 * Time O(N)
 * Space O(N)
 * */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if( !root )
            return {};

        std::stack< std::pair< TreeNode*, int > > stack;
        stack.emplace( root, 0 );

        vector< int > result;

        while( !stack.empty() ) {
            auto [ node, level] = stack.top();
            stack.pop();

            if( result.size() == level )
                result.push_back( node->val );

            if( node->left )
                stack.emplace( node->left, level + 1 );
            if( node->right )
                stack.emplace( node->right, level + 1 );
        }

        return result;
    }
};
} // namespace V1

namespace {
/*
N - number of nodes

Time O(N)
Space O(N) - need store view
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector< int > view;
        rightSideView( root, view, 0 );
        return view;
    }

private:
    void rightSideView( TreeNode* node, std::vector< int >& view, int depth ) {
        if( !node )
            return;
        
        if( view.size() == depth ) {
            view.push_back( node->val ); 
        }
        
        rightSideView( node->right, view, depth + 1 );
        rightSideView( node->left, view, depth + 1 );
    }
};
} // namespace

namespace {
/*
Time O(N)
Space O(N)
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector< int > view;
        if( ! root )
            return view;
        
        std::queue< TreeNode* > queue;
        queue.emplace( root );
        
        while( ! queue.empty() ) {
            const int levelSize = queue.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto node = queue.front();
                queue.pop();
                
                if( i == 0 )
                    view.push_back( node->val );
                
                if( node->right )
                    queue.push( node->right );
                if( node->left )
                    queue.push( node->left );
            }
        }
        
        return view;
    }
};
}