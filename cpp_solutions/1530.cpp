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
    int result = 0;
    vector<int> traverse(TreeNode* node, int distance) {
        if (!node) return vector<int>(11, 0);
        if (node->left == nullptr && node->right == nullptr) {
            vector<int> res = vector<int>(11, 0);
            res[0] = 1;
            return res;
        }
        vector<int> l = traverse(node->left, distance);
        vector<int> r = traverse(node->right, distance);
        for (int i = 0; i <= distance; ++i) {
            for (int j = 0; j <= distance - i - 2; ++j) {
                result += l[i] * r[j];
            }
        }
        vector<int> res = vector<int>(11, 0);
        for (int i = 0; i <= 9; ++i) {
            res[i + 1] = l[i] + r[i];
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        traverse(root, distance);
        return result;
    }
};
