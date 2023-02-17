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
    int prev = -1;
    int curr = -1;
    int res = INT_MAX;
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        prev = curr;
        curr = node->val;
        if (prev != -1) {
            res = min(res, curr - prev);
        }
        dfs(node->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// v2
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
    int res = INT_MAX;
    int minVal = INT_MIN / 2;
    void preorder(TreeNode* node) {
        if (!node) return;
        preorder(node->left);
        res = min(res, node->val - minVal);
        minVal = node->val;
        preorder(node->right);
    }
    int minDiffInBST(TreeNode* root) {
        preorder(root);
        return res;
    }
};