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
    int resCount = 0;
    // count and sum
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        int currCount = 1;
        int currSum = node->val;
        
        if (node->left) {
            vector<int> res = dfs(node->left);
            currCount += res[0];
            currSum += res[1];
        }
        if (node->right) {
            vector<int> res = dfs(node->right);
            currCount += res[0];
            currSum += res[1];
        }
        if ((currSum / currCount) == node->val) resCount++;
        return {currCount, currSum};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return resCount;
    }
};