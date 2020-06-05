/*
https://leetcode.com/problems/reverse-string/
*/

#pragma once

#include <unordered_set>

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

namespace V1 {
class Solution {
public:
    bool hasCycle( ListNode * head ) {
        std::unordered_set< ListNode * > set;
        while( head ) {
            if( !set.insert( head ).second )
                return true;

            head = head->next;
        }

        return false;
    }
};
} // namespace V1

namespace V2 {
/*
 * This approach is called "slow and fast pointers".
 * We move slow point one node at time and fast pointer two node at time. If there is a cycle, then they
 * will definitely meet each other.
 *
 * Time O(n + k) -> (n), k = cyclic length
 * Space O(1)
 * */
class Solution {
public:
    bool hasCycle( ListNode * head ) {
        auto p = head;
        auto q = head;

        while( p && q && q->next ) {
            p = p->next;
            q = q->next->next;

            if( p == q )
                return true;
        }

        return false;
    }
};
} // namespace V2
