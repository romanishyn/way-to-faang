/*
 * https://leetcode.com/problems/path-sum-iii/
 * */

#include <stack>
#include <unordered_map>

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
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
      if( !root )
        return 0;

      int pathCount = 0;

      std::stack< TreeNode* > stack;
      stack.emplace( root );

      while( !stack.empty() ) {
        auto node = stack.top();
        stack.pop();

        pathCount += searchPaths( node, sum );

        if( node->left )
          stack.emplace( node->left );
        if( node->right )
          stack.emplace( node->right );
      }

      return pathCount;
    }

private:
    int searchPaths( TreeNode* node, int sum ) {
      if( !node )
        return 0;

      sum -= node->val;

      int pathCount = 0;

      if( sum == 0 )
        ++pathCount;

      return pathCount + searchPaths( node->left, sum ) + searchPaths( node->right, sum );
    }
};
} // namespace V1

namespace V2 {
class Solution {

    using FrequencyOfPrefixSum = std::unordered_map< int, int >;

public:
    int pathSum(TreeNode* root, int sum) {
        FrequencyOfPrefixSum frequencyOfPrefixSum;
        frequencyOfPrefixSum[ 0 ] = 1;
        return pathSum( root, sum, 0, frequencyOfPrefixSum );
    }

private:
    int pathSum(TreeNode* node, int sum, int prefixSum, FrequencyOfPrefixSum& frequencyOfPrefixSum ) {
        if( !node )
            return 0;

        prefixSum += node->val;

        int pathCounter = 0;
        if( auto it = frequencyOfPrefixSum.find( prefixSum - sum ); it != frequencyOfPrefixSum.end() )
            pathCounter += it->second;

        ++frequencyOfPrefixSum[ prefixSum ];

        pathCounter += pathSum( node->left, sum, prefixSum, frequencyOfPrefixSum );
        pathCounter += pathSum( node->right, sum, prefixSum, frequencyOfPrefixSum );

        --frequencyOfPrefixSum[ prefixSum ];

        return pathCounter;
    }
};
} // namespace V2
