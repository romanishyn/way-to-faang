/*
https://leetcode.com/problems/linked-list-random-node/
*/

#include <random>

namespace {
/*
Space O(1)
Time O(1) - constructor
Time O(N) - getRandom
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
private:
    ListNode* head;
    std::default_random_engine randomEngine;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head)
    :   head{ head }
    ,   randomEngine{ std::default_random_engine{} }
    {
    }

    /** Returns a random node's value. */
    int getRandom() {
        auto curr = head;
        int val = 0;
        int counter = 0;
        while( curr ) {
            std::uniform_int_distribution<int> distribution{ 0, counter };
            if( counter == distribution( randomEngine ) ) {
                val = curr->val;
            }

            curr = curr->next;
            ++counter;
        }

        return val;
    }
};
} // namespace
