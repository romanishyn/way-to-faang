/*
https://leetcode.com/problems/merge-k-sorted-lists/
*/

#pragma once

#include <vector>
#include <unordered_set>
#include <queue>

using std::vector;

// TODO: impl Divide and Conquer without recursion

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

namespace V1 {
/*
 * Time ??? O(Nlogk)
 * Space (k) k - size of lists
 * */

struct comparator {
    bool operator () (const ListNode* lhs, const ListNode* rhs ) const {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* current = &dummy;

        std::priority_queue< ListNode*, std::vector<ListNode*>,comparator > queue;
        for( auto node : lists ) {
            if( node )
                queue.push( node );
        }

        while( !queue.empty() ) {
            current->next = queue.top();
            queue.pop();

            current = current->next;

            if( current->next ) {
                queue.push( current->next );
            }
        }

        return dummy.next;
    }
};
} // namespace V1

namespace V2 {
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.empty() )
            return nullptr;

        return mergeKListsImpl( lists, 0, lists.size() );
    }

    ListNode* mergeKListsImpl( const vector<ListNode*>& lists, int beginIdx, int endIdx ) {
        if( endIdx - beginIdx == 1)
            return lists[ beginIdx ];

        const int midIdx = ( beginIdx + endIdx ) >> 1;

        return mergeTwoLists(
                mergeKListsImpl( lists, beginIdx, midIdx )
            ,   mergeKListsImpl( lists, midIdx, endIdx )
        );
    }

    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ) {
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
} // namespace V2