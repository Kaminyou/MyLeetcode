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
    int deepestLevel = 0;
    int sum = 0;
    void dfs(TreeNode* node, int level) {
        if (node == nullptr) return;
        if (level == deepestLevel) sum += node->val;
        if (level > deepestLevel) {
            deepestLevel = level;
            sum = node->val;
        }
        if (node->left) dfs(node->left, level + 1);
        if (node->right) dfs(node->right, level + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};