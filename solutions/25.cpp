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
    ListNode* recursive(ListNode* node, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        
        // test k
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return node;
        curr = node;
        for (int i = 0; i < k; ++i) {
            ListNode* temp = curr;
            ListNode* prevTemp = prev;
            prev = curr;
            curr = curr->next;
            temp->next = prevTemp;
        }
        node->next = recursive(curr, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentinel = new ListNode(0, head);
        sentinel->next = recursive(sentinel->next, k);
        return sentinel->next;
    }
};