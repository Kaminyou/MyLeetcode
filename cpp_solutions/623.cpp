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
    void dfs(TreeNode* node, int currDepth, int val, int depth) {
        if (node == nullptr) return;
        TreeNode* curr = node;
        if (currDepth + 1 == depth) {
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = node->left;
            node->left = left;
            right->right = node->right;
            node->right = right;
        }
        dfs(curr->left, currDepth + 1, val, depth);
        dfs(curr->right, currDepth + 1, val, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root, 1, val, depth);
        return root;
    }
};