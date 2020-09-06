/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

#include <vector>
#include <stack>

using std::vector;

namespace {
/*
Split problem into two subproblems: Iterative inorder traversal and Merge Sorted Array

N - number of nodes in first tree (root1)
M - number of nodes in second tree (root2)

Time O(N+M)
Space O(N+M)
*/
  //Definition for a binary tree node.
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        auto elements1 = getSortedElements( root1 );
        auto elements2 = getSortedElements( root2 );
        mergeTwoArray( elements1, elements2 );
        return elements1;
    }

private:
    vector< int > getSortedElements( const TreeNode* node ) {
        vector< int > result;
        std::stack< const TreeNode* > todo;

        while( ! todo.empty() || node ) {
            while( node ) {
                todo.push( node );
                node = node->left;
            }

            node = todo.top();
            todo.pop();

            result.push_back( node->val );

            node = node->right;
        }

        return result;
    }

    void mergeTwoArray( vector< int >& target, vector< int >& source ) {
        int size1 = target.size();
        int size2 = source.size();
        int targetIdx = size1 - 1;
        int sourceIdx = size2 - 1;

        target.resize( size1 + size2 );
        int writeIdx = target.size() - 1;

        while( targetIdx >= 0 && sourceIdx >= 0 ) {
            if( target[ targetIdx ] < source[ sourceIdx ] )
                target[ writeIdx ] = source[ sourceIdx-- ];
            else
                target[ writeIdx ] = target[ targetIdx-- ];

            --writeIdx;
        }

        std::copy_n( source.begin(), sourceIdx + 1, target.begin() );
    }
};
} // namespace

namespace {
/*
Approach: One pass

Time O(N+M)
Space O(N+M)
*/
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::stack< TreeNode* > stack1;
        std::stack< TreeNode* > stack2;

        vector< int > result;
        while( ! stack1.empty() || ! stack2.empty() || root1 || root2 ) {
            while( root1 ) {
                stack1.push( root1 );
                root1 = root1->left;
            }

            while( root2 ) {
                stack2.push( root2 );
                root2 = root2->left;
            }

            if( stack2.empty() || ( ! stack1.empty() && stack1.top()->val < stack2.top()->val ) ) {
                root1 = stack1.top();
                stack1.pop();
                result.push_back( root1->val );
                root1 = root1->right;
            }
            else {
                root2 = stack2.top();
                stack2.pop();
                result.push_back( root2->val );
                root2 = root2->right;
            }
        }

        return result;
    }
};
} // namespace