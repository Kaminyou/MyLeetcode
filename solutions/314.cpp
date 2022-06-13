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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        unordered_map<int, vector<int>> mp;
        int minPos = INT_MAX;
        int maxPos = INT_MIN;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            minPos = min(minPos, pos);
            maxPos = max(maxPos, pos);
            mp[pos].push_back(node->val);
            if (node->left) q.push(make_pair(node->left, pos - 1));
            if (node->right) q.push(make_pair(node->right, pos + 1));
        }
        int range = maxPos - minPos + 1;
        res.resize(range);
        for (auto& element : mp) {
            res[element.first - minPos] = element.second;
        }
        return res;
    }
};