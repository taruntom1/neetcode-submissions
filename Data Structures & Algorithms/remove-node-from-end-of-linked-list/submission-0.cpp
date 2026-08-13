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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;

        auto dummy = new ListNode(0, head);

        ListNode* pt_l = dummy;
        ListNode* pt_t = dummy;

        while (pt_l) {
            if (count > n) pt_t = pt_t->next;
            pt_l = pt_l->next;
            count++;
        }

        if (pt_t->next) {
            auto nxt = pt_t->next->next;
            delete pt_t->next;
            pt_t->next = nxt;
        } else {
            delete pt_t->next;
            pt_t->next = NULL;
        }

        return dummy->next;
    }
};
