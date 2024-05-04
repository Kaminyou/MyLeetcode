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
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->left;
            height++;
        }
        return height;
    }
    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->right;
            height++;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = getLeftHeight(root->left);
        int rightHeight = getRightHeight(root->right);
        if (leftHeight == rightHeight) return (1 << (leftHeight + 1)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
class Solution {
public:
    int getHeight(TreeNode* node) {
        int res = 0;
        while (node) {
            res++;
            node = node->left;
        }
        return res;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int height = getHeight(root);
        return (getHeight(root->right) == height - 1) ? (1 << (height - 1)) + countNodes(root->right) : (1 << (height - 2)) + countNodes(root->left);
    }
};