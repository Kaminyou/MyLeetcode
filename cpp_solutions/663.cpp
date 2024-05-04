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
    int dfsGetSum(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfsGetSum(node->left);
        int right = dfsGetSum(node->right);
        node->val = left + right + node->val;
        return node->val;
    }
    bool checkEqual(TreeNode* node, int sum) {
        if (node == nullptr) return false;
        // cut left
        if (node->left) {
            int leftSum = node->left->val;
            if (leftSum == sum - (leftSum)) return true;
        }
        // cur right
        if (node->right) {
            int rightSum = node->right->val;
            if (rightSum == sum - (rightSum)) return true;
        }
        if (checkEqual(node->left, sum) || checkEqual(node->right, sum)) return true;
        return false;
    }
    bool checkEqualTree(TreeNode* root) {
        int sum = dfsGetSum(root);
        return checkEqual(root, sum);
    }
};