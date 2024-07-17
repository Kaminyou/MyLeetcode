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
    bool parse(TreeNode* node, unordered_set<int>& st, vector<TreeNode*>& res, bool isRoot) {
        if (!node) return false;
        if (st.count(node->val)) {
            bool l = parse(node->left, st, res, true);
            bool r = parse(node->right, st, res, true);
            if (!l) node->left = nullptr;
            if (!r) node->right = nullptr;
            return false;
        }
        else {
            if (isRoot) res.push_back(node);
            bool l = parse(node->left, st, res, false);
            bool r = parse(node->right, st, res, false);
            if (!l) node->left = nullptr;
            if (!r) node->right = nullptr;
            return true;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        parse(root, st, res, true);
        return res;
    }
};
