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
    void dfs(TreeNode* node, int level, unordered_map<int, int>& levelSum) {
        if (!node) return;
        levelSum[level] += node->val;
        dfs(node->left, level + 1, levelSum);
        dfs(node->right, level + 1, levelSum);
    }
    void dfs2(TreeNode* node, int level, unordered_map<int, int>& levelSum) {
        if (!node) return;
        int leftVal = 0;
        int rightVal = 0;
        if (node->left) leftVal = node->left->val;
        if (node->right) rightVal = node->right->val;
        
        int valForNextLevel = levelSum[level + 1] - leftVal - rightVal;
        if (node->left) node->left->val = valForNextLevel;
        if (node->right) node->right->val = valForNextLevel;
        dfs2(node->left, level + 1, levelSum);
        dfs2(node->right, level + 1, levelSum);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> levelSum;
        dfs(root, 0, levelSum);
        if (root) root->val = 0;
        dfs2(root, 0, levelSum);
        return root;
    }
};