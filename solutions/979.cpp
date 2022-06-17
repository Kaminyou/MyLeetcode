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
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int coins = node->val;
        coins += dfs(node->left);
        coins += dfs(node->right);
        res += abs(coins - 1);
        return coins - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};