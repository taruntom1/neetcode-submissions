/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;

        s.push(root);

        while (!s.empty()) {
            auto n = s.top();
            s.pop();

            if (!n) continue;

            if (n->val == subRoot->val) {
                if (isSameTree(n, subRoot)) return true;
            }

            s.push(n->right);
            s.push(n->left);
        }

        return false;
    }

   private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;

        s1.push(p);
        s2.push(q);

        while (!(s1.empty() || s2.empty())) {
            auto n1 = s1.top();
            auto n2 = s2.top();
            s1.pop();
            s2.pop();

            if ((!n1 && n2) || (n1 && !n2)) return false;
            if (!(n1 || n2)) continue;
            if (n1->val != n2->val) return false;

            s1.push(n1->left);
            s1.push(n1->right);
            s2.push(n2->left);
            s2.push(n2->right);
        }

        if (s1.empty() && s1.empty()) return true;

        return false;
    }
};
