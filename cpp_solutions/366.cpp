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
    vector<vector<int>> res;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int depth = max(left, right);
        if (res.size() == depth) {
            res.push_back({node->val});
        }
        else {
            res[depth].push_back(node->val);
        }
        return depth + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};