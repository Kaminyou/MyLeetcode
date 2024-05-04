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
    vector<TreeNode*> allPossibleFBT(int n) {
        if ((n & 1) == 0) return {};
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode());
        for (int i = 3; i <= n; i += 2) {
            for (int j = 1; j < i; j += 2) {
                int k = i - j - 1;
                for (auto& l : dp[j]) {
                    for (auto& r : dp[k]) {
                        TreeNode* root = new TreeNode();
                        root->left = l;
                        root->right = r;
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};