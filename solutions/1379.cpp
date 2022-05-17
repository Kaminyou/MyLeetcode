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
    TreeNode* res;
    void dfs(TreeNode* origin, TreeNode* clone, TreeNode* target) {
        if (origin == nullptr) return;
        if (origin == target) {
            res = clone;
            return;
        }
        if (origin->left) dfs(origin->left, clone->left, target);
        if (origin->right) dfs(origin->right, clone->right, target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(original, cloned, target);
        return res;
    }
};