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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sentinelLess = new ListNode(0);
        ListNode* sentinelGreater = new ListNode(0);
        ListNode* less = sentinelLess;
        ListNode* greater = sentinelGreater;
        
        while (head) {
            if (head->val >= x) {
                greater->next = head;
                greater = greater->next;
            }
            else {
                less->next = head;
                less = less->next;
            }
            head = head->next;
        }
        less->next = sentinelGreater->next;
        greater->next = nullptr;
        return sentinelLess->next;
    }
};