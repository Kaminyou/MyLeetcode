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
    void collectLeaf(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        if (root->left || root->right) {
            collectLeaf(root->left, nodes);
            collectLeaf(root->right, nodes);
        }
        else {
            nodes.push_back(root->val);
        }
     }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1;
        vector<int> nodes2;
        collectLeaf(root1, nodes1);
        collectLeaf(root2, nodes2);
        if (nodes1.size() != nodes2.size()) return false;
        int n = nodes1.size();
        for (int i = 0; i < n; ++i) {
            if (nodes1[i] != nodes2[i]) return false;
        }
        return true;
    }
};