/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

#include <vector>
#include <stack>

using std::vector;

namespace {
/*
H - hight of tree

Time O(H+H)->(H)
Space O(H)
*/
	class Solution {
	public:
		Node* lowestCommonAncestor(Node* p, Node * q) {
			std::unordered_set< Node* > nodes;
			while (p) {
				nodes.insert(p);
				p = p->parent;
			}

			while (q) {
				if (nodes.count(q))
					return q;
				q = q->parent;
			}

			return nullptr;
		}
	};
} // namespace

namespace {
/*
H - hight of tree

Time O(H+H)->(H)
Space O(1)
*/
class Solution {
public:
	Node* lowestCommonAncestor(Node* p, Node * q) {
		auto node1 = p;
		auto node2 = q;
		while (node1 != node2) {
			node1 = node1 == nullptr ? q : node1->parent;
			node2 = node2 == nullptr ? p : node2->parent;
		}
		return node1;
	}
};
} // namespace