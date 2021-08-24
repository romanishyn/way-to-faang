/*
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * */

#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using std::vector;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace V1 {
/*
 * Build undirected graph, but store only child-parent mapping, since the parent-child mapping is inherent in the tree structure
 * Do BFS with source vertex (target) to find all vertexes with distance K to it.
 *
 * N - number of nodes
 * Time (N)
 * Space (N)
 * */
class Solution {
public:
    using NodeToParent = std::unordered_map< TreeNode*, TreeNode* >;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        auto nodeToParent = createNodeToParentMap( root );

        std::queue< TreeNode* > q;
        std::unordered_set< TreeNode* > seen;

        q.push( target );
        seen.insert( target );

        int level = 0;

        while( !q.empty() ) {
            const int levelSize = q.size();

            if( level == K ) {
                break;
            }

            for( int i = 0; i < levelSize; ++i ) {
                auto node = q.front();
                q.pop();

                if( node->left && !seen.count( node->left ) ) {
                    q.push( node->left );
                    seen.insert( node->left );
                }
                if( node->right && !seen.count( node->right ) ) {
                    q.push( node->right );
                    seen.insert( node->right );
                }
                auto parent = nodeToParent[ node ];
                if( parent && !seen.count( parent ) ) {
                    q.push( parent );
                    seen.insert( parent );
                }
            }

            ++level;
        }

        std::vector< int > result;
        while( !q.empty() ) {
            result.push_back( q.front()->val );
            q.pop();
        }

        return result;
    }

private:
    NodeToParent createNodeToParentMap( TreeNode* root ) {
        NodeToParent result;

        std::queue< TreeNode* > q;
        q.push( root );

        while( !q.empty() ) {
            auto node = q.front();
            q.pop();

            if( node->left ) {
                result[ node->left ] = node;
                q.push( node->left );
            }
            if( node->right ) {
                result[ node->right ] = node;
                q.push( node->right );
            }
        }

        return result;
    }
};
} // namespace V1

// TODO: impl with kind of clone tree https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143752/JAVA-Graph-%2B-BFS
namespace V2 {
/*
 * */
} // namespace V2


namespace {
/*
N - number of nodes

Time (N)
Space O(N)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map< TreeNode*, TreeNode* > nodeToParent;
        fillParents( root, nullptr, nodeToParent );
        
        std::queue< TreeNode* > todo;
        std::unordered_set< TreeNode* > seen;
        todo.push( target );
        seen.insert( target );
        
        while( k ) {
            const int levelSize = todo.size();
            for( int i = 0; i < levelSize; ++i ) {
                auto node = todo.front();
                todo.pop();
                
                if( nodeToParent[ node ] && seen.insert( nodeToParent[ node ] ).second )
                    todo.push( nodeToParent[ node ] );
                if( node->left && seen.insert( node->left ).second )
                    todo.push( node->left );
                if( node->right && seen.insert( node->right ).second )
                    todo.push( node->right );
            } 
            
            --k;
        }
        
        std::vector< int > result;
        while( ! todo.empty() ) {
            auto node = todo.front();
            todo.pop();
            result.push_back( node->val );
        }
        
        return result;
    }
    
private:
    void fillParents( TreeNode* node, TreeNode* parent, std::unordered_map< TreeNode*, TreeNode* >& nodeToParent)
    {
        if( ! node )
            return;
        
        nodeToParent[ node ] = parent;
        
        fillParents( node->left, node, nodeToParent );
        fillParents( node->right, node, nodeToParent );
    }
};
} // namespace