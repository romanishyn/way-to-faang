/*
 * https://leetcode.com/problems/reverse-linked-list-ii/
 * */

 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

namespace V1 {
/*
 * Time (N)
 * Space (1)
 * */
class Solution {
public:
    ListNode * reverseBetween( ListNode * head, int m, int n ) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for( int i = 0; i < m - 1; ++i ) { // "- 1"
            prev = curr;
            curr = curr->next;
        }

        auto lastNodeOfFirstPart = prev;
        auto subListTail = curr;

        for( int i = 0; i < n - m + 1; ++i ) { // "+ 1"
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        subListTail->next = curr;

        if( lastNodeOfFirstPart ) {
            lastNodeOfFirstPart->next = prev; // prev is subListHead
        }
        else {
            head = prev;
        }

        return head;
    }
};
} // namespace V1
