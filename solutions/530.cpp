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
    int lastValue = INT_MIN / 2;
    int minDiff = INT_MAX;
    void traverse(TreeNode* node) {
        if (node == nullptr) return;
        traverse(node->left);
        minDiff = min(minDiff, node->val - lastValue);
        lastValue = node->val;
        traverse(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traverse(root);
        return minDiff;
    }
};