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
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next && head->next->next) {
            head->next->next = swapPairs(head->next->next);
        }
        if (head && head->next) {
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = head;
            return temp;
        }
        return head;
    }
};