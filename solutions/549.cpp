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
    int res = 1;
    // des, ins
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        if (node->left == nullptr && node->right == nullptr) return {1, 1};
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        
        // case 1: both and left->node->right
        if (node->left && node->right && node->val - 1 == node->left->val && node->val + 1 == node->right->val) {
            res = max(res, 1 + left[0] + right[1]);
        }
        // case 2: both and right->node->left
        if (node->left && node->right && node->val - 1 == node->right->val && node->val + 1 == node->left->val) {
            res = max(res, 1 + left[1] + right[0]);
        }
        int des = 1;
        int ins = 1;
        //case 3: left->node or node->left
        if (node->left) {
            if (node->val - 1 == node->left->val) {
                res = max(res, 1 + left[0]);
                des = max(des, 1 + left[0]);
            }
            if (node->val + 1 == node->left->val) {
                res = max(res, 1 + left[1]);
                ins = max(ins, 1 + left[1]);
            }
        }
        //case 4: right->node or node->right
        if (node->right) {
            if (node->val - 1 == node->right->val) {
                res = max(res, 1 + right[0]);
                des = max(des, 1 + right[0]);
            }
            if (node->val + 1 == node->right->val) {
                res = max(res, 1 + right[1]);
                ins = max(ins, 1 + right[1]);
            }
        }
        return {des, ins};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
};