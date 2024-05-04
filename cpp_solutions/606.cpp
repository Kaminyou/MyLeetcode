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
    string res;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        
        res += to_string(node->val);
        if (node->left || node->right) {
            res.push_back('(');
            dfs(node->left);
            res.push_back(')');
            if (node->right) {
                res.push_back('(');
                dfs(node->right);
                res.push_back(')');
            }
        }
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        return res;
    }
};