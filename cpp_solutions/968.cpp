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
    int res = 0;
    int dfs(TreeNode* node) {
        // 0: is a leave
        // 1: set camera
        // 2: is not leave but is covered
        if (node == nullptr) return 2;
        int left = dfs(node->left);
        int right = dfs(node->right);
        // if any of its child is a leave => set
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        // if any of its child has camera => not set
        if (left == 1 || right == 1) {
            return 2;
        }
        // left == right == 2
        // both of its children have been cover or do not exist
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int state = dfs(root);
        if (state == 0) res++;
        return res;
    }
};