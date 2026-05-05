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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int n = 0;
        while (curr) {
            prev = curr;
            curr = curr->next;
            n++;
        }
        if (n == 0) return head;
        k = n - k % n;
        if (k == n) return head;
        ListNode* sentinel = new ListNode(0, head);
        curr = sentinel;
        while (k--) {
            curr = curr->next;
        }
        ListNode* temp = sentinel->next;
        sentinel->next = curr->next;
        prev->next = temp;
        curr->next = nullptr;
        return sentinel->next;
    }
};
