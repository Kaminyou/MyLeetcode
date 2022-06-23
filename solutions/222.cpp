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
    int getHeight(TreeNode* node) {
        int res = 0;
        while (node) {
            res++;
            node = node->left;
        }
        return res;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int height = getHeight(root);
        return (getHeight(root->right) == height - 1) ? (1 << (height - 1)) + countNodes(root->right) : (1 << (height - 2)) + countNodes(root->left);
    }
};