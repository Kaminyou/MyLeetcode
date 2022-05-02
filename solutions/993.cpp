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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) return false;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            bool xFlag = false;
            bool yFlag = false;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->val == x) xFlag = true;
                if (node->val == y) yFlag = true;
                
                if (xFlag && yFlag) return true;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                if (node->left && node->right && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))) return false;
            }
        }
        return false;
    }
};