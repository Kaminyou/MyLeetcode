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
    int res = 0;
    bool dfs(TreeNode* node) {
        if (node == nullptr) return true;
        bool left = dfs(node->left);
        bool right = dfs(node->right);
        if (left && right) {
            if ((node->left == nullptr || node->val == node->left->val) 
                && (node->right == nullptr || node->val == node->right->val)) {
                res++;
                return true;
            }
            else return false;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};