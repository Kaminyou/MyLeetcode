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
    void traverse(TreeNode* node, int depth, int& maxDepth) {
        if (!node) return;
        maxDepth = max(maxDepth, depth);
        traverse(node->left, depth + 1, maxDepth);
        traverse(node->right, depth + 1, maxDepth);
    }
    int maxDepth(TreeNode* root) {
        int res = 0;
        traverse(root, 1, res);
        return res;
    }
};