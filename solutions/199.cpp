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
    vector<int> res;
    void dfs(TreeNode* node, int level) {
        if (node == nullptr) return;
        if (res.size() == level) res.push_back(node->val);
        if (node->right) dfs(node->right, level + 1);
        if (node->left) dfs(node->left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};