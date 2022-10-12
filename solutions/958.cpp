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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty() && q.front() != nullptr) {
            auto node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while (!q.empty() && q.front() == nullptr) q.pop();
        return q.empty();
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
    int dfsMaxDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfsMaxDepth(node->left);
        int right = dfsMaxDepth(node->right);
        return max(left, right) + 1;
    }
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        int maxDepth = dfsMaxDepth(root);
        
        int level = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool stop = false;
        while (!q.empty()) {
            int n = q.size();
            
            if (level <= maxDepth - 2 && n != (1 << level)) return false;
            if (level <= maxDepth - 3) {
                for (int i = 0; i < n; ++i) {
                    auto node = q.front();
                    q.pop();
                    if (!node->left && node->right) return false;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            else {
                for (int i = 0; i < n; ++i) {
                    auto node = q.front();
                    q.pop();
                    if (!stop) {
                        if (!node->left && node->right) return false;
                        if (!node->left && !node->right) stop = true;
                        if (node->left && !node->right) stop = true;
                    }
                    else {
                        if (node->left) return false;
                        if (node->right) return false;
                    }
                }
            }
            level++;
        }
        
        return true;
    }
};