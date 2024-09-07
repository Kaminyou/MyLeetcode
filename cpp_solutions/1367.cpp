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
    vector<TreeNode*> targets;
    void find(TreeNode* node, int val) {
        if (node) {
            if (node->val == val) {
                targets.push_back(node);
            }
            find(node->left, val);
            find(node->right, val);
        }
    }
    bool check(ListNode* cur, TreeNode* node) {
        if (cur == nullptr) return true;
        if (node == nullptr) return false;
        if (node->val != cur->val) return false;
        if (check(cur->next, node->left) || check(cur->next, node->right)) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        find(root, head->val);
        for (auto& target : targets) {
            if (check(head, target)) return true;
        }
        return false;
    }
};
