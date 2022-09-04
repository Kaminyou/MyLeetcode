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
    map<int, map<int, multiset<int>>> memo;
    void dfs(TreeNode* node, int row, int col) {
        if (node == nullptr) return;
        memo[col][row].insert(node->val);
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& colElement : memo) {
            vector<int> col;
            for (auto& rowElement : colElement.second) {
                for (auto& element : rowElement.second) {
                    col.push_back(element);
                }
            }
            res.push_back(col);
        } 
        return res;
    }
};