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
    int res = 0;
    // inc, dec
    pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) return {0, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int increase = 0;
        int decrease = 0;
        if (node->left != nullptr && node->left->val + 1 == node->val) {
            increase = max(increase, left.first);
        }
        if (node->right != nullptr && node->right->val + 1 == node->val) {
            increase = max(increase, right.first);
        }
        if (node->left != nullptr && node->left->val - 1 == node->val) {
            decrease = max(decrease, left.second);
        }
        if (node->right != nullptr && node->right->val - 1 == node->val) {
            decrease = max(decrease, right.second);
        }
        res = max(res, 1 + increase + decrease);
        return {increase + 1, decrease + 1};
    }
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
};

// V2
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int res = 1;
//     // des, ins
//     vector<int> dfs(TreeNode* node) {
//         if (node == nullptr) return {0, 0};
//         if (node->left == nullptr && node->right == nullptr) return {1, 1};
//         vector<int> left = dfs(node->left);
//         vector<int> right = dfs(node->right);
        
//         // case 1: both and left->node->right
//         if (node->left && node->right && node->val - 1 == node->left->val && node->val + 1 == node->right->val) {
//             res = max(res, 1 + left[0] + right[1]);
//         }
//         // case 2: both and right->node->left
//         if (node->left && node->right && node->val - 1 == node->right->val && node->val + 1 == node->left->val) {
//             res = max(res, 1 + left[1] + right[0]);
//         }
//         int des = 1;
//         int ins = 1;
//         //case 3: left->node or node->left
//         if (node->left) {
//             if (node->val - 1 == node->left->val) {
//                 res = max(res, 1 + left[0]);
//                 des = max(des, 1 + left[0]);
//             }
//             if (node->val + 1 == node->left->val) {
//                 res = max(res, 1 + left[1]);
//                 ins = max(ins, 1 + left[1]);
//             }
//         }
//         //case 4: right->node or node->right
//         if (node->right) {
//             if (node->val - 1 == node->right->val) {
//                 res = max(res, 1 + right[0]);
//                 des = max(des, 1 + right[0]);
//             }
//             if (node->val + 1 == node->right->val) {
//                 res = max(res, 1 + right[1]);
//                 ins = max(ins, 1 + right[1]);
//             }
//         }
//         return {des, ins};
//     }
//     int longestConsecutive(TreeNode* root) {
//         dfs(root);
//         return res;
//     }
// };