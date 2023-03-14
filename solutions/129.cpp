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
    int sum = 0;
    void dfs(TreeNode* node, int current) {
        current *= 10;
        current += node->val;
        if (!node->left && !node->right) {
            sum += current;
        }
        if (node->left) dfs(node->left, current);
        if (node->right) dfs(node->right, current);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};