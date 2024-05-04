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
    int res = 0;
    // in each node, steal or not steal
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return make_pair(0, 0);
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int steal = node->val + l.second + r.second;
        int notSteal = max(l.first, l.second) + max(r.first, r.second);
        res = max(res, steal);
        res = max(res, notSteal);
        return make_pair(steal, notSteal);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return res;
    }
};