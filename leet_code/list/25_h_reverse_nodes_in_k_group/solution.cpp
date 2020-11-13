/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

namespace {
/*
N - number of nodes

Time O(N)
Space O(1)
*/
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( ! head || k <= 1 )
            return head;

        ListNode* prev = nullptr;
        auto curr = head;

        while( curr ) {
            auto lastNodePrevPart = prev;
            
            auto tailCurrPart = curr;
            auto currNode = curr;
            for( int i = 0; i < k; ++i ) {
                if( ! curr )
                    return head;
                curr = curr->next;
            }

            auto headRightPart = curr;

            while( currNode != headRightPart ) {
                auto next = currNode->next;
                currNode->next = prev;
                prev = currNode;
                currNode = next;
            }

            if( ! lastNodePrevPart )
                head = prev;
            else
                lastNodePrevPart->next = prev;

            tailCurrPart->next = headRightPart;
            prev = tailCurrPart;
        }

        return head;
    }
};
} // namespace


namespace {
/*
N - number of nodes
K - k

Time O(N)
Space O(N/K)
*/
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto curr = head;
        int count = 0;
        for( ; count < k && curr; ++count )
            curr = curr->next;

        if( count == k ) {
            auto prev = reverseKGroup( curr, k );

            for( ; count > 0; --count ) {
                auto next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }

            head = prev;
        }

        return head;
    }
};
} // namespace
