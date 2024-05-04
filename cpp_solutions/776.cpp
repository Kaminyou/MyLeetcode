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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        vector<TreeNode*> res = {nullptr, nullptr};
        if (root == nullptr) return res;
        if (root->val <= target) {
            res[0] = root;
            auto right = splitBST(root->right, target);
            root->right = right[0];
            res[1] = right[1];
        }
        else {
            res[1] = root;
            auto left = splitBST(root->left, target);
            root->left = left[1];
            res[0] = left[0];
        }
        return res;
    }
};