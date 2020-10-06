/*
https://leetcode.com/problems/binary-tree-vertical-order-traversal/
*/

#include <vector>
#include <map>
#include <stack>

using std::vector;

namespace {
/*
BFS

N - number of nodes

Time O(NlogN)
Space O(N)
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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if( ! root )
            return {};

        std::map< int, std::vector< int > > verticals;
        std::queue< std::pair< TreeNode*, int > > todo;
        todo.emplace( root, 0 );

        while( ! todo.empty() ) {
            auto [ node, verticalIdx ] = todo.front();
            todo.pop();

            verticals[ verticalIdx ].push_back( node->val );

            if( node->left )
                todo.emplace( node->left, verticalIdx - 1 );
            if( node->right )
                todo.emplace( node->right, verticalIdx + 1 );
        }

        std::vector< std::vector< int > > result;
        for( auto& [_, vertical] : verticals )
            result.push_back( std::move( vertical ) );

        return result;
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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if( ! root )
            return {};

        std::map< int/*x*/, std::map< int/*y*/, std::vector< int > > > tree;

        std::stack< std::tuple< TreeNode*, int/*x*/, int/*y*/ > > todo;
        todo.emplace( root, 0, 0 );

        while( ! todo.empty() ) {
            auto [node, x, y] = todo.top();
            todo.pop();

            tree[ x ][ y ].push_back( node->val );

            if( node->right )
                todo.emplace( node->right, x + 1, y + 1 );
            if( node->left )
                todo.emplace( node->left, x - 1, y + 1 );
        }

        std::vector< std::vector< int > > result;

        for( auto& [x, vertical] : tree ) {
            std::vector< int > vals;

            for( auto& [y, values] : vertical ) {
                std::copy( values.begin(), values.end(), std::back_inserter( vals ) );
            }

            result.push_back( std::move( vals ) );
        }

        return result;
    }
};
} // namespace

namespace {
/*
BFS
using leftCol and rightCol indices allows avoid sorting by colIdx

N - number of nodes

Time O(N)
Space O(N)
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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if( ! root )
            return {};
        
        int leftCol = 0;
        int rightCol = 0;
        std::queue< std::pair< TreeNode*, int > > todo;
        todo.emplace( root, 0 );
        std::unordered_map< int, std::vector< int > > verticals;

        while( ! todo.empty() ) {
            auto [ node, colIdx ] = todo.front();
            todo.pop();

            verticals[ colIdx ].push_back( node->val );
            leftCol = std::min( leftCol, colIdx );
            rightCol = std::max( rightCol, colIdx );

            if( node->left )
                todo.emplace( node->left, colIdx - 1 );
            if( node->right )
                todo.emplace( node->right, colIdx + 1 );
        }

        std::vector< std::vector< int > > result;
        for( int i = leftCol; i <= rightCol; ++i ) {
            result.push_back( std::move( verticals[ i ] ) );
        }

        return result;
    }
};
} // namespace

namespace {
/*
DFS
using leftCol and rightCol indices allows avoid sorting by colIdx

N - number of nodes
W - width of tree
H - hight of tree

Time O(W*HlogH)
Space O(N)
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

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if( ! root )
            return {};

        int leftCol = 0;
        int rightCol = 0;
        std::stack< std::tuple< TreeNode*, int/*col*/, int /*row*/ > > todo;
        todo.emplace( root, 0, 0 );

        std::unordered_map< int/*col*/, std::map< int/*row*/, std::vector<int> > > verticals;

        while( ! todo.empty() ) {
            auto [node, col, row] = todo.top();
            todo.pop();

            leftCol = std::min( leftCol, col );
            rightCol = std::max( rightCol, col );
            verticals[ col ][ row ].push_back( node->val );

            if( node->right )
                todo.emplace( node->right, col + 1, row + 1 );
            if( node->left )
                todo.emplace( node->left, col - 1, row + 1 );
        }

        std::vector< std::vector< int > > result;
        for( int i = leftCol; i <= rightCol; ++i ) {
            std::vector< int > resultVertical;
            for( auto& [_, vertical] : verticals[ i ] ) {
                std::copy( vertical.begin(), vertical.end(), std::back_inserter( resultVertical ) );
            }
            result.push_back( std::move( resultVertical ) );
        }

        return result;
    }
};
} // namespace

