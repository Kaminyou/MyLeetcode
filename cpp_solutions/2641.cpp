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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> tempQ;
        if (root) {
            q.push(root);
            root->val = 0;
        }
        while (!q.empty()) {
            int nextSum = 0;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                tempQ.push(node);
                if (node->left) {
                    nextSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    nextSum += node->right->val;
                    q.push(node->right);
                }
            }
            while (!tempQ.empty()) {
                TreeNode* node = tempQ.front();
                tempQ.pop();
                int nextVal = nextSum;
                if (node->left) {
                    nextVal -= node->left->val;
                }
                if (node->right) {
                    nextVal -= node->right->val;
                }
                if (node->left) {
                    node->left->val = nextVal;
                }
                if (node->right) {
                    node->right->val = nextVal;
                }
            }
        }
        return root;
    }
};

