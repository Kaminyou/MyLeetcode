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
    // res is the max zigzag path
    int res = 0;
    // left and right path of current node
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return make_pair(-1, -1);
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        pair<int, int> out = make_pair(left.second + 1, right.first + 1);
        res = max(res, out.first);
        res = max(res, out.second);
        return out;
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return res;
    }
};