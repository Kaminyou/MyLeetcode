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
    vector<vector<int>> out;
    void traverse(TreeNode* node, vector<int> curr, int targetSum){
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == targetSum) {
                curr.push_back(node->val);
                out.push_back(curr);
                curr.pop_back();
            }
        }
        if (node->left != nullptr) {
            curr.push_back(node->val);
            traverse(node->left, curr, targetSum - node->val);
            curr.pop_back();
        }
        if (node->right != nullptr){
            curr.push_back(node->val);
            traverse(node->right, curr, targetSum - node->val);
            curr.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        traverse(root, curr, targetSum);
        return out;
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
    vector<vector<int>> res;
    void dfs(TreeNode* node, int currentSum, int targetSum, vector<int>& path) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            if (currentSum == targetSum) {
                res.push_back(path);
            }
            return;
        }
        if (node->left) {
            path.push_back(node->left->val);
            dfs(node->left, currentSum + node->left->val, targetSum, path);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            dfs(node->right, currentSum + node->right->val, targetSum, path);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if (root) {
            path.push_back(root->val);
            dfs(root, root->val, targetSum, path);
            path.pop_back();
        }
        return res;
    }
};