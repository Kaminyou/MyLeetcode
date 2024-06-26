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
    vector<int> nodes;
    void traverse(TreeNode* node) {
        if (!node) return;
        traverse(node->left);
        nodes.push_back(node->val);
        traverse(node->right);
    }
    TreeNode* construct(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = construct(left, mid - 1);
        node->right = construct(mid + 1, right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return construct(0, nodes.size() - 1);
    }
};
