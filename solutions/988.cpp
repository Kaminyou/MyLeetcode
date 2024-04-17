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
    string res = "";
    string current = "";
    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        current.push_back(node->val + 'a');
        dfs(node->left);
        dfs(node->right);
        if (node->left == nullptr && node->right == nullptr) {
            reverse(current.begin(), current.end());
            if (res == "") res = current;
            else {
                if (current < res) res = current;
            }
            reverse(current.begin(), current.end());
        }
        current.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return res;
    }
};
