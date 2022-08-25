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
    int minVal;
    int secondMinVal;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        if (node->val != minVal) {
            if (secondMinVal == -1) secondMinVal = node->val;
            else secondMinVal = min(secondMinVal, node->val);
        }
        if (secondMinVal != -1 && node->val > secondMinVal) return;
        dfs(node->left);
        dfs(node->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        minVal = root->val;
        secondMinVal = -1;
        dfs(root);
        return secondMinVal;
    }
};