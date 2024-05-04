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
    void dfs(TreeNode* node, TreeNode* parent, int length) {
        if (node == nullptr) return;
        if (parent != nullptr && node->val - parent->val == 1) length++;
        else length = 1;
        res = max(res, length);
        dfs(node->left, node, length);
        dfs(node->right, node, length);
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root, nullptr, 0);
        return res;
    }
};