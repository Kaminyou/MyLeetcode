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
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) return {INT_MIN, INT_MAX, 0};
        vector<int> curr = {node->val, node->val, 1};
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        if (node->left) {
            if (left[2] == -1) return {node->val, node->val, -1};
            if (node->val > left[1]) {
                curr[0] = left[0];
                curr[2] += left[2];
            }
            else {
                curr[2] = -1;
            }
        }
        if (node->right) {
            if (right[2] == -1) return {node->val, node->val, -1};
            if (node->val < right[0]) {
                curr[1] = right[1];
                curr[2] += right[2];
            }
            else {
                curr[2] = -1;
            }
        }
        res = max(res, curr[2]);
        return curr;
    }
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};