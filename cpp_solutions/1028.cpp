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
    TreeNode* _recoverFromPreorder(string traversal, int& index, int depth) {
        if (index >= traversal.size()) return nullptr;
        int currDepth = 0;
        while (traversal[index] == '-') {
            index++;
            currDepth++;
        }
        if (currDepth < depth) {
            index -= currDepth;
            return nullptr;
        }
        int val = 0;
        while (isdigit(traversal[index])) {
            val = val * 10 + traversal[index] - '0';
            index++;
        }
        TreeNode* node = new TreeNode(val);
        node->left = _recoverFromPreorder(traversal, index, depth + 1);
        node->right = _recoverFromPreorder(traversal, index, depth + 1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return _recoverFromPreorder(traversal, index, 0);
    }
};
