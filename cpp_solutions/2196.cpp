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
    TreeNode* build(int nodeIdx, unordered_map<int, int>& node2left, unordered_map<int, int>& node2right) {
        TreeNode* node = new TreeNode(nodeIdx);
        if (node2left.find(nodeIdx) != node2left.end()) {
            node->left = build(node2left[nodeIdx], node2left, node2right);
        }
        if (node2right.find(nodeIdx) != node2right.end()) {
            node->right = build(node2right[nodeIdx], node2left, node2right);
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> nodes;
        unordered_map<int, int> inDegrees;
        unordered_map<int, int> node2left;
        unordered_map<int, int> node2right;
        for (auto& description : descriptions) {
            nodes.insert(description[0]);
            nodes.insert(description[1]);
            inDegrees[description[1]] += 1;
            if (description[2] == 1) {
                node2left[description[0]] = description[1];
            }
            else {
                node2right[description[0]] = description[1];
            }
        }
        int rootIdx = -1;
        for (auto& node : nodes) {
            if (inDegrees.find(node) == inDegrees.end()) {
                rootIdx = node;
                break;
            }
        }
        return build(rootIdx, node2left, node2right);
    }
};
