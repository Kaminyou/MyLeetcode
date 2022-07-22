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
    TreeNode* curr;
    TreeNode* sentinel;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        
        curr->right = node;
        curr->left = nullptr;
        curr = curr->right;
        
        dfs(left);
        dfs(right);
    }
    void flatten(TreeNode* root) {
        sentinel = new TreeNode(0);
        curr = sentinel;
        dfs(root);
        root = sentinel->right;
    }
};