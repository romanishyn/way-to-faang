/*
 * https://leetcode.com/problems/maximum-width-of-binary-tree/
 * */

#include <queue>

namespace {
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val( 0 ), left( nullptr ), right( nullptr ) {}

    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {}

    TreeNode( int x, TreeNode * left, TreeNode * right ) : val( x ), left( left ), right( right ) {}
};
}

namespace V1 {
/*
 * The idea is use heap indexing:
             1
       2         3
     4   5     6   7
    8 9 x 11  x 13 x 15

 Regardless whether these nodes exists:
 - always make id of left child as parentId * 2
 - always make id of right child as parentId * 2 + 1

 Note: size of Idx

 We use Breadth First Search, iterate level by level, in the begining each levele we remember left index and right, since
 if one node on the level they are the same. Then proccessing all node on current level and update right index at each iteration.
 When we finished proccesing level check if current length is the longest so far, if so, remember value.

 N - number of nodes in the tree

 Time(N) since we visit all nodes only once
 Space(N) ??? (w)
 * */
class Solution {
public:
    using Idx = long unsigned;

    int widthOfBinaryTree(TreeNode* root) {
        if( !root )
            return 0;

        Idx maxLength = 0;

        std::queue< std::pair< TreeNode*, Idx > > queue;
        queue.emplace( root, 1 );

        while( !queue.empty() ) {
            const Idx left = queue.front().second;
            Idx right = left;

            for( int i = 0, levelSize = queue.size(); i < levelSize; ++i ) {
                auto [ node, idx ] = queue.front();
                queue.pop();

                right = idx;

                if( node->left )
                    queue.emplace( node->left, idx * 2 );
                if( node->right )
                    queue.emplace( node->right, idx * 2 + 1 );
            }

            maxLength = std::max( maxLength, right - left + 1 );
        }

        return static_cast< Idx >( maxLength );
    }
};
} // namespace V1