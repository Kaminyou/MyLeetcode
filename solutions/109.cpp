/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;
    TreeNode* dfs(int n) {
        if (n == 0) return nullptr;
        TreeNode* left = dfs(n / 2);
        
        TreeNode* node = new TreeNode(curr->val);
        curr = curr->next;
        
        TreeNode* right = dfs(n - n / 2 - 1);
        node->left = left;
        node->right = right;
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        int n = 0;
        curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;
        return dfs(n);
    }
};