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
    vector<int> res;
    int currentCnt = 0;
    int maxCnt = 0;
    int currentValue = INT_MIN;
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        if (node->val == currentValue) {
            currentCnt++;
        }
        else {
            currentCnt = 1;
            currentValue = node->val;
        }
        if (currentCnt > maxCnt) {
            maxCnt = currentCnt;
            res.clear();
        }
        if (currentCnt == maxCnt) {
            res.push_back(node->val);
        }
        inorder(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
