/*
 * https://leetcode.com/problems/path-sum-ii/
 * */

#include <vector>

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
 * Dificalte analyze problem: it's either O(NlogN) or O(N^2)
 * */
class Solution {

    using Path = vector< int >;
    using Paths = vector< Path >;

public:
    vector< vector< int>> pathSum( TreeNode * root, int sum ) {
        Paths result;
        Path path;
        pathSum( root, sum, result, path );
        return result;
    }

private:
    void pathSum( TreeNode* node, int sum, Paths& result, Path& path ) {
        if( !node )
            return;

        sum -= node->val;
        path.push_back( node->val );

        pathSum( node->left, sum, result, path );
        pathSum( node->right, sum, result, path );

        if( isLeaf( node ) && sum == 0 )
            result.push_back( path );

        path.pop_back();
    }

    bool isLeaf( const TreeNode* node ) {
        return !node->left && !node->right;
    }
};
} // namespace V1
