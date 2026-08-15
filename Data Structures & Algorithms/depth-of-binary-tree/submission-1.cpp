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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        int ret = 0;

        s.push({root, 0});

        while (!s.empty()) {
            auto [n, c] = s.top();
            s.pop();

            ret = max(ret, c++);

            if (!n) continue;

            s.push({n->left, c});
            s.push({n->right, c});
        }
        return ret;
    }
};
