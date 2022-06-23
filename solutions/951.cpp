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
    bool dfs(TreeNode* node1, TreeNode* node2) {
        
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr || node1->val != node2->val) return false;
        
        return (dfs(node1->left, node2->left) && dfs(node1->right, node2->right)) || (dfs(node1->left, node2->right) && dfs(node1->right, node2->left));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};

// v2
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
//     bool dfs(TreeNode* node1, TreeNode* node2) {
//         if (node1 == nullptr && node2 == nullptr) return true;
//         if (node1 == nullptr || node2 == nullptr) return false;
//         if (node1->val != node2->val) return false;
//         bool originalLeft = dfs(node1->left, node2->left);
//         bool originalRight = dfs(node1->right, node2->right);
//         bool exchangeLeft = dfs(node1->left, node2->right);
//         bool exchangeRight = dfs(node1->right, node2->left);
//         return ((originalLeft && originalRight) || (exchangeLeft && exchangeRight));
//     }
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         return dfs(root1, root2);
//     }
// };