/*
https://leetcode.com/problems/reverse-string/
*/

#pragma once

#include <stack>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace V1 {
class Solution {
public:
    ListNode * reverseList( ListNode * head ) {
        std::stack< ListNode * > stack;

        while( head ) {
            stack.push( head );
            head = head->next;
        }

        ListNode * tail{ nullptr };
        while( !stack.empty() ) {
            if( !tail ) {
                head = tail = stack.top();
            } else {
                tail->next = stack.top();
                tail = tail->next;
            }

            tail->next = nullptr;
            stack.pop();
        }

        return head;
    }
    /*
    ListNode * reverseList( ListNode * head ) {
        if( !head )
            return head;

        std::stack< ListNode * > stack;

        while( head->next ) {
            stack.push( head );
            head = head->next;
        }

        ListNode * newHead = head;
        while( !stack.empty() ) {
            head->next = stack.top();
            head = head->next;
            stack.pop();
        }

        head->next = nullptr;

        return newHead;
    }
     */
};
} // namespace V1

namespace V2 {
class Solution {
public:
    ListNode * reverseList( ListNode * head ) {
        ListNode* newHead{ nullptr };
        ListNode* tail{ nullptr };

        while( head ) {
            newHead = head;
            head = head->next;

            if( !tail ) {
                tail = newHead;
                tail->next = nullptr;
            }
            else {
                newHead->next = tail;
                tail = newHead;
            }
        }

        return newHead;
    }
};
} // namespace V2

namespace V3 {
class Solution {
public:
    ListNode * reverseList( ListNode * head ) {
        ListNode* prevNode{ nullptr };
        ListNode* newHead{ nullptr };

        return helper( prevNode, newHead, head );
    }

private:
    ListNode* helper( ListNode* prevNode, ListNode* newHead, ListNode* head ) {
        if( !head )
            return newHead;

        newHead = head;
        head = head->next;

        if( !prevNode ) {
            prevNode = newHead;
            prevNode->next = nullptr;
        }
        else {
            newHead->next = prevNode;
            prevNode = newHead;
        }

        return helper( prevNode, newHead, head );
    }
};
} // namespace V3

namespace V4 {
/*
 * While we traversing the list, we need change current node's next pointer to previous node.
 * Since we dont have 'new' previous node reference, we must store previous node in separate variable and update its
 * when we handel current node.
 * Also we need temporary variable for next node in list, before we change reference to next node in current processing node.
 * And at the end return new head reference.
 * */
class Solution {
public:
    ListNode * reverseList( ListNode * head ) {
        ListNode* prev{ nullptr };

        while( head ) {
            auto tempNext = head->next;
            head->next = prev;
            prev = head;
            head = tempNext;
        }

        return prev;
    }
};
} // namespace V4

namespace V5 {
/*
 * Back to back SWE: https://www.youtube.com/watch?v=O0By4Zq0OFc
 * */
class Solution {
public:
    ListNode * reverseList( ListNode * head ) {
        if( !head || !head->next )
            return head;

        auto reverseListHead = reverseList( head->next );
        head->next->next = head;
        head->next = nullptr; // curr pointer to null since we don't know if this is the first node in the list.
        return reverseListHead;
    }
};
} // namespace V5