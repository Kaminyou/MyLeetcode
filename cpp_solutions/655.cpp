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
    int height = 0;
    void getHeight(TreeNode* node, int currHeight) {
        if (node == nullptr) return;
        height = max(height, currHeight);
        getHeight(node->left, currHeight + 1);
        getHeight(node->right, currHeight + 1);
    }
    void dfs(TreeNode* node, int x, int y, vector<vector<string>>& res) {
        if (node == nullptr) return;
        res[x][y] = to_string(node->val);
        dfs(node->left, x + 1, y - pow(2, height - x - 1), res);
        dfs(node->right, x + 1, y + pow(2, height - x - 1), res);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        getHeight(root, 0);
        int n = pow(2, height + 1) - 1;
        vector<vector<string>> res(height + 1, vector<string>(n, ""));
        dfs(root, 0, (n - 1) / 2, res);
        return res;
    }
};