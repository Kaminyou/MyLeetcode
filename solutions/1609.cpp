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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int evenCurrent = -1;
            int oddCurrent = INT_MAX;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                // odd
                if (level) {
                    if (node->val & 1) return false;
                    if (node->val >= oddCurrent) return false;
                    oddCurrent = node->val;
                }
                else {
                    if (!(node->val & 1)) return false;
                    if (node->val <= evenCurrent) return false;
                    evenCurrent = node->val;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            level ^= 1;
        }
        return true;
    }
};
