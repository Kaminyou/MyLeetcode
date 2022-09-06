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
        if (node == nullptr) return false;
        bool current = (node->val == 1);
        bool left = dfs(node->left);
        bool right = dfs(node->right);
        if (!left) node->left = nullptr;
        if (!right) node->right = nullptr;
        return (current || left || right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool res = dfs(root);
        if (!res) return nullptr;
        return root;
    }
};