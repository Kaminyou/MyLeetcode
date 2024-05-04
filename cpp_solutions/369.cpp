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
class Solution {
public:
    int dfs(ListNode* node) {
        int plus = 1;
        if (node->next != nullptr) {
            plus = dfs(node->next);
        }
        int num = node->val + plus;
        node->val = num % 10;
        return num / 10;
    }
    ListNode* plusOne(ListNode* head) {
        int plus = dfs(head);
        if (plus) {
            ListNode* append = new ListNode(plus);
            append->next = head;
            return append;
        }
        return head;
    }
};