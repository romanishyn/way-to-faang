/*
https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
*/

namespace {
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
} // namespace 

namespace {
/*
Not the best solution

Requer not only stack, but also vector

N - number of nodes

Time O(N)
Space O(N)
*/
class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (!root)
			return root;

		std::vector< Node* > nodes;

		std::stack< Node* > stack;
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

		for (int i = 1; i < nodes.size(); ++i) {
			nodes[i - 1]->right = nodes[i];
			nodes[i]->left = nodes[i - 1];
		}

		nodes.front()->left = nodes.back();
		nodes.back()->right = nodes.front();

		return nodes.front();
	}
};
} // namespace


