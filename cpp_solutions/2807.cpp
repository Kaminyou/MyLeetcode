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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* previous = sentinel;
        ListNode* current = head;
        while (current) {
            if (previous->val != -1) {
                int a = previous->val;
                int b = current->val;
                int c = __gcd(a, b);
                ListNode* temp = new ListNode(c, current);
                previous->next = temp;
            }
            previous = current;
            current = current->next;
        }
        return sentinel->next;
    }
};
