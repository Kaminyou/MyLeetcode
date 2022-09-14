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
    bool isPalindromic(vector<int>& hash) {
        int even = 0;
        int odd = 0;
        for (int i = 0; i < 10; ++i) {
            if (hash[i] & 1) odd++;
            else even++;
        }
        if (odd > 1) return false;
        else return even > 0;
    }
    void dfs(TreeNode* node, vector<int>& hash) {
        if (node == nullptr) return;
        hash[node->val]++;
        if (node->left == nullptr && node->right == nullptr) {
            if (isPalindromic(hash)) res++;
            hash[node->val]++;
            return;
        }
        dfs(node->left, hash);
        dfs(node->right, hash);
        hash[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        dfs(root, hash);
        return res;
    }
};