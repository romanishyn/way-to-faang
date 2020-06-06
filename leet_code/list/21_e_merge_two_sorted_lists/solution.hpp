/*
https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head{ nullptr };
        ListNode* tail{ nullptr };
        ListNode* temp{ nullptr };

        while( l1 || l2 ) {
            if( l1 && l2 ) {
                if( l1->val < l2->val ) {
                    temp = l1->next;
                    insertNode( head, tail, l1 );
                    l1 = temp;
                }
                else {
                    temp = l2->next;
                    insertNode( head, tail, l2 );
                    l2 = temp;
                }
            }
            else if( l1 ) {
                temp = l1->next;
                insertNode( head, tail, l1 );
                l1 = temp;
            }
            else {
                temp = l2->next;
                insertNode( head, tail, l2 );
                l2 = temp;
            }
        }

        return head;
    }

private:
    void insertNode( ListNode*& head, ListNode*& tail, ListNode*& node ) {
        if( !head ) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = tail->next;
        }

        tail->next = nullptr;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if( !l1 ) return l2;
        if( !l2 ) return l1;

        ListNode* head{ nullptr };
        ListNode* tail{ nullptr };

        while( l1 && l2 ) {
            if( l1->val < l2->val ) {
                insertNode( head, tail, l1 );
                l1 = l1->next;
            }
            else {
                insertNode( head, tail, l2 );
                l2 = l2->next;
            }
        }

        tail->next = l1 ? l1 : l2;

        return head;
    }

private:
    void insertNode( ListNode*& head, ListNode*& tail, ListNode*& node ) {
        // if list is empty
        if( !head )
            head = node;
        // if list contains elements, then connect last element with new one
        else
            tail->next = node;

        // new element becomes latest in the list
        tail = node;
    }
};
} // namespace V2

namespace V3 {
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;

        while( l1 && l2 ) {
            if( l1->val < l2->val ) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        current->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
} // namespace V3
