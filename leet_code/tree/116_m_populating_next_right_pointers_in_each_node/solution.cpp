/*
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * */

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


namespace V1 {
/*
 * We are going traver tree in following approach: create two-level nested loop, outer loop iterating over each level,
 * over first node of each level. Inner loop iterating over each node a single level. To have oportunity move on to the
 * next level, we will remember next first left child node befor enter the inner loop, call it levelStart.
 *
 * N - number of nodes
 *
 * Time O(N), since we visit each once
 * Space O(N), there is no extra space allocation
 * */
class Solution {
public:
    Node* connect(Node* root) {
        Node* levelStart = nullptr;

        auto currNode = root;

        while( currNode ) {
            levelStart = currNode->left;

            while( currNode && levelStart ) {
                currNode->left->next = currNode->right;

                if( currNode->next )
                    currNode->right->next = currNode->next->left;

                currNode = currNode->next;
            }

            currNode = levelStart;
        }

        return root;
    }
};
} // namespace V1