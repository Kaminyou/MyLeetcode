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
    vector<TreeNode*> backtracking(int left, int right) {
        if (left > right) return {nullptr};
        vector<TreeNode*> res;
        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> leftTrees = backtracking(left, i - 1);
            vector<TreeNode*> rightTrees = backtracking(i + 1, right);
            for (auto lt : leftTrees) {
                for (auto rt : rightTrees) {
                    TreeNode* node = new TreeNode(i, lt, rt);
                    res.push_back(node);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return backtracking(1, n);
    }
};