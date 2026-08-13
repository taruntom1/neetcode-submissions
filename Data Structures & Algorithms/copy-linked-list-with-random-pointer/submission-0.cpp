/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;

        auto dummy = new Node(0);
        auto pt1 = head;
        auto pt2 = dummy;
        while (pt1) {
            pt2->next = new Node(pt1->val);
            m[pt1] = pt2->next;
            pt1 = pt1->next;
            pt2 = pt2->next;
        }

        pt1 = head;
        pt2 = dummy->next;
        while (pt1) {
            pt2->random = m[pt1->random];
            pt1 = pt1->next;
            pt2 = pt2->next;
        }

        return dummy->next;
    }
};
