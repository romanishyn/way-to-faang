/*
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * */

#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

namespace V1 {
/*
 * first implementation
 *
 * Time (N*N) ?
 * Space (N)
 * */
class Solution {
public:
    Node * flatten( Node * head ) {
        if( !head )
            return head;

        auto newNext = flatten( head->next );
        auto newChild = flatten( head->child );
        head->child = nullptr;

        auto tail = head;

        while( newChild ) {
            tail->next = newChild;
            newChild->prev = tail;
            newChild = newChild->next;
            tail = tail->next;
        }

        if( newNext ) {
            tail->next = newNext;
            newNext->prev = tail;
        }

        return head;
    }
};
} // namespace V1

namespace V2 {
/*
 * N - total number of nodes;
 * Time (N)
 * Space (N)
 * */
class Solution {
public:
    Node * flatten( Node * head ) {
        if( !head )
            return head;

        std::stack< Node* > stack;
        stack.push( head );
        Node* prev = nullptr;

        while( !stack.empty() ) {
            auto node = stack.top();
            stack.pop();

            if( prev ) {
                node->prev = prev;
                prev->next = node;
            }

            if( node->next ) {
                stack.push( node->next );
            }
            if( node->child ) {
                stack.push( node->child );
                node->child = nullptr;
            }

            prev = node;
        }

        return head;
    }
};
} // namespace V2
