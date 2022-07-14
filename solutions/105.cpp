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
    int current = 0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[current++]);
        
        int currentIdx;
        for (int i = left; i <= right; ++i) {
            if (inorder[i] == node->val) {
                currentIdx = i;
                break;
            }
        }
        node->left = build(preorder, inorder, left, currentIdx - 1);
        node->right = build(preorder, inorder, currentIdx + 1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int left = 0;
        int right = preorder.size() - 1;
        return build(preorder, inorder, left, right);
    }
};