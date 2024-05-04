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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* sentinel = new ListNode(0, head);
        ListNode* prev = sentinel;
        ListNode* curr = head;
        
        for (int i = 0; i < left - 1; ++i) {
            curr = curr->next;
            prev = prev->next;
        }
        ListNode* leftBound = prev;
        ListNode* leftMost = curr;
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode* temp = curr;
            ListNode* tempPrev = prev;
            prev = curr;
            curr = curr->next;
            temp->next = tempPrev;
        }
        leftMost->next = curr;
        leftBound->next = prev;
        
        return sentinel->next;
    }
};