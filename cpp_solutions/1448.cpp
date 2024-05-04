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
    void dfs(TreeNode* node, int currentMax) {
        if (node == nullptr) return;
        if (node->val >= currentMax) res++;
        dfs(node->left, max(currentMax, node->val));
        dfs(node->right, max(currentMax, node->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }
};