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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            
            if ((level & 1) == 1) {
                vector<TreeNode*> memo;
                vector<int> values;
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = q.front();
                    memo.push_back(node);
                    values.push_back(node->val);
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                reverse(values.begin(), values.end());
                for (int i = 0; i < n; ++i) {
                    memo[i]->val = values[i];
                }
            }
            else {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};