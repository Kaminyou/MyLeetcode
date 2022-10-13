/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp;
        while (node->next != nullptr) {
            node->val = node->next->val;
            temp = node;
            node = node->next;
        }
        temp->next = nullptr;
    }
};