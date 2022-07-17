/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* current, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& mp) {
        if (current == nullptr) return;
        if (parent) mp[current].push_back(parent);
        if (current->left) mp[current].push_back(current->left);
        if (current->right) mp[current].push_back(current->right);
        dfs(current->left, current, mp);
        dfs(current->right, current, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        dfs(root, nullptr, mp);
        
        vector<int> res;
        unordered_set<TreeNode*> st;
        queue<TreeNode*> q;
        q.push(target);
        st.insert(target);
        
        int path = 0;
        while (!q.empty() && path <= k) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (path == k) {
                    res.push_back(node->val);
                    continue;
                }
                for (auto& neighbor : mp[node]) {
                    if (st.count(neighbor)) continue;
                    q.push(neighbor);
                    st.insert(neighbor);
                }
            }
            path++;
        }
        return res;
    }
};