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
    int curr = INT_MAX;
    TreeNode* res = nullptr;
    void dfs(TreeNode* node, TreeNode* p) {
        if (node == nullptr) return;
        if (node->val <= p->val) dfs(node->right, p);
        else {
            curr = node->val;
            res = node;
            dfs(node->left, p);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        return res;
    }
};