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
        if (node == p) return node;
        if (node == q) return node;
        
        TreeNode* left = nullptr;
        if (node->val > p->val || node->val > q->val) left = dfs(node->left, p, q);
        TreeNode* right = nullptr;
        if (node->val < p->val || node->val < q->val) right = dfs(node->right, p, q);
        
        if (left && right) return node;
        else if (left) return left;
        else if (right) return right;
        else return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};