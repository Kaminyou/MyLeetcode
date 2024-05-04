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

    void flatten(TreeNode* node, vector<int>& v) {
        if (!node) return;
        flatten(node->left, v);
        v.push_back(node->val);
        flatten(node->right, v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nodes;
        flatten(root, nodes);
        int m = nodes.size();
        int n = queries.size();
        vector<vector<int>> res(n, vector<int>(2, -1));
        for (int i = 0; i < n; ++i) {
            int query = queries[i];
            auto it = lower_bound(nodes.begin(), nodes.end(), query); // >=
            if (it != nodes.end()) {
                int index = it - nodes.begin();
                res[i][1] = nodes[index];
            }
            auto it2 = upper_bound(nodes.begin(), nodes.end(), query); // >
            if (it2 != nodes.begin()) {
                it2--;
                int index = it2 - nodes.begin();
                res[i][0] = nodes[index];
            }
            
        }
        return res;
    }
};