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
N - size of list

Time O(N)
Space O(1)
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto node = new Node( insertVal );

        if( ! head ) {
            node->next = node;
            return node;
        }

        auto end = head;
        while( end->next != head && end->val <= end->next->val )
            end = end->next;

        auto begin = end->next;
        while( begin != end && ! ( begin->val <= insertVal && begin->next->val >= insertVal ) )
            begin = begin->next;

        node->next = begin->next;
        begin->next = node;

        return head;
    }
};
} // namespace

namespace {
/*
N - size of list

Time O(N)
Space O(1)
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto node = new Node( insertVal );

        if( ! head ) {
            node->next = node;
            return node;
        }

        auto prev = head;
        auto curr = head->next;

        bool needInsert = false;

        do {
            if( prev->val <= insertVal && insertVal <= curr->val ) {
                break;
            }
            else if( prev->val > curr->val ) {
                if( prev->val <= insertVal || insertVal <= curr->val ) {
                    break;
                }
            }

            prev = curr;
            curr = curr->next;
        } while( curr != head );

        node->next = curr;
        prev->next = node;

        return head;
    }
};
} // namespace
