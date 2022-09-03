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
    unordered_set<int> leaveSt;
    void dfs(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& adjacency) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) leaveSt.insert(node->val);
        if (parent != nullptr) {
            adjacency[node->val].push_back(parent->val);
            adjacency[parent->val].push_back(node->val);
        }
        dfs(node->left, node, adjacency);
        dfs(node->right, node, adjacency);
    }
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<int, vector<int>> adjacency;
        dfs(root, nullptr, adjacency);
        
        // bfs
        queue<int> q;
        unordered_set<int> st;
        q.push(k);
        st.insert(k);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int node = q.front();
                q.pop();
                if (leaveSt.find(node) != leaveSt.end()) return node;
                for (auto& neighbor : adjacency[node]) {
                    if (st.find(neighbor) != st.end()) continue;
                    q.push(neighbor);
                    st.insert(neighbor);
                }
            }
        }
        return -1;
    }
};