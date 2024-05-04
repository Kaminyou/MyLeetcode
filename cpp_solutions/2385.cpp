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
    void dfs(TreeNode* node, unordered_map<int, vector<int>>& graph) {
        if (node == nullptr) return;
        if (node->left) {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            dfs(node->left, graph);
        }
        if (node->right) {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            dfs(node->right, graph);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        dfs(root, graph);
        
        unordered_set<int> visited;
        int res = -1;
        queue<int> q;
        q.push(start);
        visited.insert(start);
        
        while (!q.empty()) {
            int n = q.size();
            res++;
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                for (auto neighbor : graph[node]) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        return res;
    }
};