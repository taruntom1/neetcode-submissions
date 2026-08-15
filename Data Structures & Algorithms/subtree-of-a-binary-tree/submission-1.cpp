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
        auto haystack = serialise(root);
        auto needle = serialise(subRoot);

        return search(haystack.begin(), haystack.end(), needle.begin(), needle.end()) !=
               haystack.end();
    }

   private:
    vector<int> serialise(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto n = s.top();
            s.pop();

            if (!n) {
                v.push_back(numeric_limits<int>::max());
                continue;
            }

            v.push_back(n->val);

            s.push(n->left);
            s.push(n->right);
        }

        return v;
    }
};
