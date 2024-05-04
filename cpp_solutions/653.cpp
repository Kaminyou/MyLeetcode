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
    unordered_set<int> st;
    bool dfs(TreeNode* node, int k) {
        if (node == nullptr) return false;
        if (st.find(k - node->val) != st.end()) return true;
        st.insert(node->val);
        if (dfs(node->left, k)) return true;
        if (dfs(node->right, k)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};