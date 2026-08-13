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
    bool hasCycle(ListNode* head) {
        if(!head || !head->next) return false;
        
        
        auto its = head;
        auto itf = head->next;

        while(itf && itf->next)
        {
            if(its == itf) return true;
            its = its->next;
            itf = itf->next->next;
        }
        return false;
    }
};
