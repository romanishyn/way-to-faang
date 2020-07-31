/*
 * https://leetcode.com/problems/add-two-numbers/
 * */

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

namespace V1 {
/*
 * On the left side lest significant digits. We do simple schoolbook addition.
 * Keep track of carry using a variable and simulate digit-by-digit sum starting from the head of list,
 * which contains least-significant digit.
 *
 * L1 - length of l1
 * L2 - length of l2
 *
 * Time O(max(L1, L2))
 * Space O(1)
 * */
class Solution {
public:
    ListNode * addTwoNumbers( ListNode * l1, ListNode * l2 ) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        int carry = 0;
        while( l1 || l2 || carry > 0 ) {
            int sum = carry;

            if( l1 ) {
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2 ) {
                sum += l2->val;
                l2 = l2->next;
            }

            auto node = new ListNode( sum % 10 );
            carry = sum / 10;

            if( !curr ) {
                head = curr = node;
            }
            else {
                curr->next = node;
                curr = curr->next;
            }
        }

        return head;
    }
};
} // namespace V1
