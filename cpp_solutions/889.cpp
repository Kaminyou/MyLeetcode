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
    TreeNode* construct(vector<int>& preorder, int& idx, vector<int>& postorder, int left, int right) {
        cout << idx << " " << left << " " << right << endl;
        if (idx >= preorder.size()) return nullptr;
        if (left > right) return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        if (left == right) return node;
        int middle = right;
        while (postorder[middle] != preorder[idx]) middle--;
        node->left = construct(preorder, idx, postorder, left, middle);
        node->right = construct(preorder, idx, postorder, middle + 1, right - 1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int idx = 0;
        return construct(preorder, idx, postorder, 0, preorder.size() - 1);
    }
};

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
    int preIdx = 0;
    int postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[preIdx]);
        preIdx++;
        if (node->val != postorder[postIdx]) {
            node->left = constructFromPrePost(preorder, postorder);
        }
        if (node->val != postorder[postIdx]) {
            node->right = constructFromPrePost(preorder, postorder);
        }
        postIdx++;
        return node;
    }
};