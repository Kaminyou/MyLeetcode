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
    bool dfs(TreeNode* node, int targetSum) {
        if (node == nullptr) return false;
        if (node->left == nullptr && node->right == nullptr) {
            if (targetSum == node->val) return true;
            return false;
        }
        bool left = dfs(node->left, targetSum - node->val);
        bool right = dfs(node->right, targetSum - node->val);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};