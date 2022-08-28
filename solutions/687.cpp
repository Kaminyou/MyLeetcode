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
    // {value, length}
    int res = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        auto [leftValue, leftLength] = dfs(node->left);
        auto [rightValue, rightLength] = dfs(node->right);
        int currLength = 1;
        int returnLength = 0;
        if (leftValue == node->val) {
            currLength += leftLength;
            returnLength = max(returnLength, leftLength);
        }
        if (rightValue == node->val) {
            currLength += rightLength;
            returnLength = max(returnLength, rightLength);
        }
        res = max(res, currLength - 1);
        return {node->val, returnLength + 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};