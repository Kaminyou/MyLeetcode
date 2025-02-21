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
class FindElements {
public:
    unordered_set<int> st;
    void dfs(TreeNode* node, int current) {
        if (!node) return;
        node->val = current;
        st.insert(current);
        if (node->left) dfs(node->left, current * 2 + 1);
        if (node->right) dfs(node->right, current * 2 + 2);
    }
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
