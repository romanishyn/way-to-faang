/*
https://leetcode.com/problems/binary-tree-paths/
*/

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace {
/*
Recursive DFS

N - number of nodes
H - hight of tree

Time (N*H)
Space (N*H)
*/
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
    using Path = std::string;
    using Paths = std::vector< Path >;

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if( ! root )
            return {};

        Paths paths;
        Path path;
        fillPaths( paths, path, root );
        return paths;
    }

private:
    void fillPaths( Paths& paths, Path& path, const TreeNode* node ) {
        const int originalSize = path.size();

        if( ! path.empty() )
            path += "->";

        path += std::to_string( node->val );
        if( isLeaf( node ) )
            paths.push_back( path );

        if( node->left )
            fillPaths( paths, path, node->left );
        if( node->right )
            fillPaths( paths, path, node->right );

        path.erase( originalSize );
    }

    bool isLeaf( const TreeNode* node ) {
        return node && ! node->left && ! node->right;
    }
};
} // namespace

namespace {
/*
Iterative DFS

N - number of nodes
H - hight of tree

Time (N*H)
Space (N*H)
*/
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if( ! root )
            return {};

        std::stack< std::pair< const TreeNode*, std::string > > todo;
        todo.emplace( root, "" );

        std::vector< std::string > paths;

        while( ! todo.empty() ) {
            auto [node, path] = todo.top();
            todo.pop();

            path += std::to_string( node->val );

            if( ! node->left && ! node->right ) {
                paths.push_back( std::move( path ) );
            }
            else {
                path += "->";

                if( node->left )
                    todo.emplace( node->left, path );
                if( node->right )
                    todo.emplace( node->right, path );
            }
        }

        return paths;
    }
};
} // namespace