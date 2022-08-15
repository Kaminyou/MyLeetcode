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
    vector<int> lb;
    vector<int> rb;
    vector<int> children;
    void dfs(TreeNode* node, bool isLeftBound, bool isRightBound) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            children.push_back(node->val);
            return;
        }
        if (isLeftBound) {
            lb.push_back(node->val);
            if (node->left != nullptr) {
                dfs(node->left, isLeftBound, false);
                dfs(node->right, false, false);
            }
            else dfs(node->right, true, false);
        }
        else if (isRightBound) {
            rb.push_back(node->val);
            if (node->right != nullptr) {
                dfs(node->left, false, false);
                dfs(node->right, false, isRightBound);
            }
            else dfs(node->left, false, true);
        }
        else {
            dfs(node->left, false, false);
            dfs(node->right, false, false);
        }
        
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        dfs(root->left, true, false);
        dfs(root->right, false, true);
        vector<int> res = {root->val};
        for (auto left : lb) res.push_back(left);
        for (auto child : children) res.push_back(child);
        int m = rb.size();
        for (int i = m - 1; i >= 0; --i) res.push_back(rb[i]);
        return res;
    }
};