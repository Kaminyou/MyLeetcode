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
    unordered_map<int, int> mp;
    int maxFreq = 0;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int current = node->val + left + right;
        mp[current]++;
        maxFreq = max(maxFreq, mp[current]);
        return current;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto& element : mp) {
            if (element.second == maxFreq) res.push_back(element.first);
        }
        return res;
    }
};