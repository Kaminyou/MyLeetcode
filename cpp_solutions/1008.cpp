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
    TreeNode* _build(vector<int>& preorder, int& curr, int bound) {
        if (curr == preorder.size() || preorder[curr] > bound) return nullptr;
        TreeNode* node = new TreeNode(preorder[curr++]);
        node->left = _build(preorder, curr, node->val);
        node->right = _build(preorder, curr, bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int curr = 0;
        return _build(preorder, curr, INT_MAX);
    }
};