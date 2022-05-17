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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        // step 1: get the middle
        // OOOOO  OOOOOO
        //   ^       ^
        ListNode* slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // step 2: reverse
        ListNode* prev = nullptr, *curr = slow, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // step 3: merge
        ListNode* firstHead = head;
        ListNode* sceondHead = prev;
        while (sceondHead->next) {
            temp = firstHead->next;
            firstHead->next = sceondHead;
            firstHead = temp;
            
            temp = sceondHead->next;
            sceondHead->next = firstHead;
            sceondHead = temp;
        }
    }
};