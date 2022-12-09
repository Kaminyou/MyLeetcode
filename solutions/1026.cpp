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
    int maxDifference = 0;
    void dfs(TreeNode* node, int currentMax, int currentMin) {
        if (!node) return;
        currentMax = max(node->val, currentMax);
        currentMin = min(node->val, currentMin);
        maxDifference = max({maxDifference, abs(currentMax - node->val), abs(currentMin - node->val)});
        dfs(node->left, currentMax, currentMin);
        dfs(node->right, currentMax, currentMin);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
        return maxDifference;
    }
};