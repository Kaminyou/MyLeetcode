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
    int widthOfBinaryTree(TreeNode* root) {
        long long res = 0;
        queue<pair<TreeNode*, long long>> q;
        if (root) q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            long long left = LLONG_MAX;
            long long right = 0;
            long long nextLeft = LLONG_MAX;
            
            for (int i = 0; i < n; ++i) {
                auto [node, position] = q.front();
                q.pop();
                left = min(left, position);
                right = max(right, position);
                if (node->left) q.push({node->left, position * 2});
                if (node->right) q.push({node->right, position * 2 + 1});
                nextLeft = min(nextLeft, position * 2);
            }
            res = max(res, right - left + 1);

            int m = q.size();
            for (int i = 0; i < m; ++i) {
                auto [node, position] = q.front();
                q.pop();
                q.push({node, position - nextLeft});
            }
        }
        return res;
    }
};