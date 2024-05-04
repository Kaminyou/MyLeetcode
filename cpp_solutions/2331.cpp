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
    bool dfs(TreeNode* node) {
        if (node->val == 0) return false;
        if (node->val == 1) return true;
        bool left = dfs(node->left);
        bool right = dfs(node->right);
        if (node->val == 2) return (left || right);
        else return left && right;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};