#include <vector>
#include <unordered_map>

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
 *
 * Time (n^2), since make find root node in INORDER for each subtree
 * Space (N)
 * */
class Solution {
public:
    TreeNode * buildTree( vector< int > & preorder, vector< int > & inorder ) {
        return buildSubtree( preorder, 0, preorder.size(), inorder, 0, inorder.size() );
    }

    TreeNode * buildSubtree( vector< int > & preorder, int preBegin, int preEnd, vector< int > & inorder, int inBegin,
                             int inEnd ) {
        if( preBegin >= preEnd )
            return nullptr;

        auto root = new TreeNode( preorder[ preBegin ] );

        int inRootIdx = -1;
        for( int i = 0; i < inorder.size(); ++i ) {
            if( inorder[ i ] == root->val ) {
                inRootIdx = i;
                break;
            }
        }

        int sizeLeftSubtree = inRootIdx - inBegin + 1;

        root->left = buildSubtree( preorder, preBegin + 1, preBegin + sizeLeftSubtree, inorder, inBegin, inRootIdx );
        root->right = buildSubtree( preorder, preBegin + sizeLeftSubtree, preEnd, inorder, inRootIdx + 1, inEnd );

        return root;
    }
};
} // namespace V1


namespace V2 {
/*
 * Time (N), we use inorderMap to speed up search of root at each subtree
 * Space (2n) -> (N)
 * */
class Solution {
public:
    TreeNode * buildTree( vector< int > & preorder, vector< int > & inorder ) {
        std::unordered_map< int, int > inorderMap;
        for( int i = 0; i < inorder.size(); ++i ) {
            inorderMap[ inorder[ i ] ] = i;
        }

        int preorderIdx = 0;
        return buildSubtree( preorder, preorderIdx, inorder, 0, inorder.size(), inorderMap );
    }

    TreeNode * buildSubtree( vector< int > & preorder, int& preorderIdx, vector< int > & inorder, int inBegin,
                             int inEnd, std::unordered_map< int, int >& inorderMap ) {
        if( inBegin >= inEnd )
            return nullptr;

        auto root = new TreeNode( preorder[ preorderIdx++ ] );

        const int inRootIdx = inorderMap[ root->val ];

        root->left = buildSubtree( preorder, preorderIdx, inorder, inBegin, inRootIdx, inorderMap );
        root->right = buildSubtree( preorder, preorderIdx, inorder, inRootIdx + 1, inEnd, inorderMap );

        return root;
    }
};
} // namespace V2
