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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto it1 = list1, it2 = list2;

        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* prev = dummy;
        while (it1 && it2) {
            if (it1->val <= it2->val) {
                prev->next = it1;
                it1 = it1->next;
            } else {
                prev->next = it2;
                it2 = it2->next;
            }
            prev = prev->next;
        }
        if (it1) prev->next = it1;
        if (it2) prev->next = it2;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};