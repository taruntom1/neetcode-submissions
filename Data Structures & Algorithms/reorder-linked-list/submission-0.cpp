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
    void reorderList(ListNode* head) {
        // finding mid point

        auto ptf = head;
        auto pts = head;

        while (ptf->next && ptf->next->next) {
            ptf = ptf->next->next;
            pts = pts->next;
        }
        auto mid = pts;
        cout << mid->val;

        // reversing second half
        ListNode* prev = NULL;

        auto n = pts->next;

        while (n) {
            auto nxt = n->next;
            n->next = prev;
            prev = n;
            n = nxt;
        }

        // merging
        auto pt1 = head;
        auto pt2 = prev;
        mid->next = nullptr;
        while (pt1 && pt2) {
            auto nxt_1 = pt1->next;
            auto nxt_2 = pt2->next;
            pt1->next = pt2;
            pt2->next = nxt_1;
            pt1 = nxt_1;
            pt2 = nxt_2;
        }
    }
};
