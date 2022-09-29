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
    void dfs(TreeNode* node, int num) {
        if (node == nullptr) return;
        num += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            res += num;
            return;
        }
        dfs(node->left, num << 1);
        dfs(node->right, num << 1);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};