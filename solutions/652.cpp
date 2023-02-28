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
    unordered_map<string, vector<TreeNode*>> mp;
    string dfs(TreeNode* node) {
        if (!node) return "N";
        string left = "R" + dfs(node->left);
        string right = "L" + dfs(node->right);
        string current = to_string(node->val) + left + right;
        mp[current].push_back(node);
        cout << current << endl;
        return current;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> res;
        for (auto& [s, nodes] : mp) {
            if (nodes.size() > 1) res.push_back(nodes[0]);
        }
        return res;
    }
};