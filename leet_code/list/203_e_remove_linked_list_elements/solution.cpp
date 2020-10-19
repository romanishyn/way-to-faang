/*
https://leetcode.com/problems/remove-linked-list-elements/
*/

namespace {
/*
N - size of list

Time O(N)
Space O(1)
*/
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy{ 0, head };
        ListNode* currNode = &dummy;

        while( currNode->next ) {
            if( currNode->next->val == val ) {
                auto removeNode = currNode->next;
                currNode->next = currNode->next->next;
                delete removeNode;
            }
            else {
                currNode = currNode->next;
            }
        }

        return dummy.next;
    }
};
} // namespace
