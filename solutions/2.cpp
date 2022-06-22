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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int buffer = 0;
        ListNode* sentinel = new ListNode();
        ListNode* curr = sentinel;
        while (l1 && l2) {
            buffer += l1->val;
            buffer += l2->val;
            l1 = l1->next;
            l2 = l2->next;
            curr->next = new ListNode(buffer % 10);
            curr = curr->next;
            buffer /= 10;
        }
        while(l1) {
            buffer += l1->val;
            l1 = l1->next;
            curr->next = new ListNode(buffer % 10);
            curr = curr->next;
            buffer /= 10;
        }
        while(l2) {
            buffer += l2->val;
            l2 = l2->next;
            curr->next = new ListNode(buffer % 10);
            curr = curr->next;
            buffer /= 10;
        }
        if (buffer) {
            curr->next = new ListNode(buffer % 10);
        }
        return sentinel->next;
    }
};