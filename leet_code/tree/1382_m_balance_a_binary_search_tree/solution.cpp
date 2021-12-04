/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

#include <vector>
#include <stack>

using std::vector;

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
*/
class Solution {
	using Nodes = std::vector< TreeNode * >;
public:
	TreeNode* balanceBST(TreeNode* root) {
		auto nodes = getSortedNodes(root);
		return balanceBST(0, nodes.size(), nodes);
	}

private:
	TreeNode* balanceBST(int begin, int end, const Nodes& nodes) {
		if (begin >= end)
			return nullptr;
		if (end - begin == 1) {
			auto node = nodes[begin];
			node->left = node->right = nullptr;
			return node;
		}

		int midIdx = begin + (end - begin) / 2;
		auto left = balanceBST(begin, midIdx, nodes);
		auto right = balanceBST(midIdx + 1, end, nodes);

		auto mid = nodes[midIdx];
		mid->left = left;
		mid->right = right;
		return mid;
	}

	Nodes getSortedNodes(TreeNode* root) {
		Nodes nodes;
		std::stack< TreeNode* > stack;
		while (!stack.empty() || root) {
			while (root) {
				stack.push(root);
				root = root->left;
			}

			root = stack.top();
			stack.pop();

			nodes.push_back(root);

			root = root->right;
		}
		return nodes;
	}
};
} // namespace

namespace {
/*
Approach: One pass

Time O(N+M)
Space O(N+M)
*/

} // namespace