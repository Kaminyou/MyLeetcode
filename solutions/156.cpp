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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return root;
        
        vector<vector<TreeNode*>> bfsResults;
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (bfsResults.size() == level) bfsResults.push_back({node});
                else bfsResults[level].push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        
        level--;
        TreeNode* newRoot = bfsResults[level][0];
        TreeNode* current = newRoot;
        while (level >= 0) {
            TreeNode* currentLevel = current;
            int n = bfsResults[level].size();
            for (int i = 1; i < n; ++i) {
                currentLevel->left = bfsResults[level][i];
                currentLevel = currentLevel->left;
            }
            currentLevel->left = nullptr;
            if (level - 1 >= 0) {
                current->right = bfsResults[level - 1][0];
                current = current->right;
            }
            else {
                current->right = nullptr;
            }
            level--;
        }
        return newRoot;
    }
};