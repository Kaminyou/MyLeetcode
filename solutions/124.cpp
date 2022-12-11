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
    int res = INT_MIN;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        
        // if the child is negative, ignore
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        int curr = left + right + node->val;
        res = max(res, curr);
        
        return max({left, right}) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

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
    int res = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int current = max({node->val, left + node->val, right + node->val});
        res = max({res, current, left + right + node->val});
        return current;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};