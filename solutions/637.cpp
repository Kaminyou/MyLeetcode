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
    vector<vector<int>> mp;
    void dfs(TreeNode* node, int level) {
        if (node == nullptr) return;
        if (mp.size() == level) mp.push_back({node->val});
        else mp[level].push_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root, 0);
        int n = mp.size();
        vector<double> res(n, 0);
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (auto& num : mp[i]) sum += num;
            sum /= (double)(mp[i].size());
            res[i] = sum;
        }
        return res;
    }
};