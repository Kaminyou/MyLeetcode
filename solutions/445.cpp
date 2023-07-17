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
    ListNode* reverse(ListNode* l){
        ListNode* prev = NULL;
        ListNode* curr = l;
        while (curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int sum = 0;
        int carry = 0;
        ListNode* l3 = new ListNode();
        ListNode* temp = l3;
        
        while (l1 || l2){
            sum = 0;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            temp->val = sum;
            
            if ((l1 || l2) || carry){
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        if (carry){
            temp->val = carry;
        }
        return reverse(l3);
    }
};