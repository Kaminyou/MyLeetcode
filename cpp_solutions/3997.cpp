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
    int traverse(TreeNode* node, int& count) {
        if (!node) return -1;
        int left = traverse(node->left, count);
        int right = traverse(node->right, count);
        int maxVal = max(left, right);
        maxVal = max(maxVal, node->val);
        if (node->val == maxVal) count++;
        return maxVal;
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        traverse(root, count);
        return count;
    }
};
