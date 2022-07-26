/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr) return nullptr;
        if (node == p) return p;
        if (node == q) return q;
        
        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);
        
        if (left == nullptr && right == nullptr) return nullptr;
        if (left && right) return node;
        if (left) return left;
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};