/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*/

#pragma once

#include <unordered_set>

//  Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        auto temp = head;

        while( temp ) {
            ++size;
            temp = temp->next;
        }

        if( n == size )
            return head->next;

        temp = head;
        for( int i = 0; i < size - n - 1; ++i ) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};
} // namespace V1

namespace V1_1 {
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;

        int size = 0;
        while( head ) {
            ++size;
            head = head->next;
        }

        size -= n;
        head = &dummy;
        while( size-- ) {
            head = head->next;
        }

        head->next = head->next->next;
        return dummy.next;
    }
};
} // namespace V1_1

namespace V2 {
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto head1 = head;
        auto head2 = head;

        for( int i = 0; i < n; ++i ) {
            head1 = head1->next;
        }

        if( !head1 )
            return head->next;

        while( head1->next ) {
            head1 = head1->next;
            head2 = head2->next;
        }

        head2->next = head2->next->next;

        return head;
    }
};
} // namespace V2

namespace V2_1 {
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;

        auto first = &dummy;
        auto second = &dummy;

        for( int i = 0; i <= n; ++i ) {
            first = first->next;
        }

        while( first ) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy.next;
    }
};
} // namespace V2
