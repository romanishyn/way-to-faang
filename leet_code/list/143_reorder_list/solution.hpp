/*
https://leetcode.com/problems/reorder-list/
*/

#pragma once

#include <stack>
#include <vector>
#include <bits/waitflags.h>

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
    void reorderList(ListNode* head) {
        std::vector< ListNode* > nodes;

        ListNode dummy;
        dummy.next = head;

        while( head ) {
            nodes.push_back( head );
            head = head->next;
        }

        ListNode* current = &dummy;
        for( int i = 0, j = nodes.size() - 1; i <= j; ++i, --j ) {
            nodes[ i ]->next = nodes[ j ];
            current->next = nodes[ i ];
            current = current->next->next;
            current->next = nullptr;
        }
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    void reorderList(ListNode* head) {
        if( !head )
            return;

        auto middle = getMiddle( head );

        auto head2 = middle->next;
        middle->next = nullptr;

        head2 = reverseList( head2 );
        mergeLists( head, head2 );
    }

private:
    ListNode* getMiddle( ListNode* head ) {
        auto slow = head;
        auto fast = head;

        while( fast && fast->next ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList( ListNode* head ) {
        ListNode* prev = nullptr;

        while( head ) {
            auto temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    void mergeLists( ListNode* l1, ListNode* l2 ) {
        ListNode dummy;
        ListNode* current = &dummy;

        while( l1 && l2 ) {
            current->next = l1;
            l1 = l1->next;

            current->next->next = l2;
            l2 = l2->next;

            current = current->next->next;
        }

        current->next = l1 ? l1 : l2;
    }
};
} // namespace V2

