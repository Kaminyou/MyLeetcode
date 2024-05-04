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
    long long sum = 0;
    long long maxVal = 0;
    long long mod = 1e9 + 7;
    void dfs(TreeNode* node) {
        if (!node) return;
        sum += node->val;
        dfs(node->left);
        dfs(node->right);
    }
    long long dfsWithMultiply(TreeNode* node) {
        if (!node) return 0;
        long long sumLeft = dfsWithMultiply(node->left);
        long long sumRight = dfsWithMultiply(node->right);
        maxVal = max(maxVal, sumLeft * (sum - sumLeft));
        maxVal = max(maxVal, sumRight * (sum - sumRight));
        return sumLeft + sumRight + node->val;
    }
    int maxProduct(TreeNode* root) {
        dfs(root);
        dfsWithMultiply(root);
        return maxVal % mod;
    }
};