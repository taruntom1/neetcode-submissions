/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        auto n = head;
        ListNode* prev = NULL;

        while (n) {
            auto temp = n->next;
            n->next = prev;

            prev = n;
            n = temp;
        }
        return prev;
    }
};
