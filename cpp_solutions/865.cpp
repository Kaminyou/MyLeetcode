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
    // depth, node contain all deepest tree
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (node == nullptr) return make_pair(0, nullptr);
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int maxDepth = max(left.first, right.first) + 1;
        TreeNode* subtree = (left.first == right.first) ? node : (left.first > right.first) ? left.second : right.second;
        return make_pair(maxDepth, subtree);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};

// V2
// class Solution {
// public:
//     int maxDepth = 0;
//     int count = 0;
//     int childrenCount = INT_MAX;
//     TreeNode* ans;
//     void dfs(TreeNode* node, int depth) {
//         if (node == nullptr) return;
//         if (depth == maxDepth) {
//             count++;
//         }
//         else if (depth > maxDepth) {
//             maxDepth = depth;
//             count = 1;
//         }
//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }
//     pair<int, int> dfsWithDepthNodes(TreeNode* node, int depth) {
//         if (node == nullptr) return make_pair(0, 0);
//         int res = (depth == maxDepth) ? 1 : 0;
//         auto left = dfsWithDepthNodes(node->left, depth + 1);
//         auto right = dfsWithDepthNodes(node->right, depth + 1);
//         res += left.first + right.first;
//         int nodeCount = left.second + right.second + 1;
//         if (res == count) {
//             if (nodeCount < childrenCount) {
//                 childrenCount = nodeCount;
//                 ans = node;
//             }
//         }
//         return make_pair(res, nodeCount);
//     }
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         dfs(root, 0);
//         dfsWithDepthNodes(root, 0);
//         return ans;
//     }
// };