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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* middle = getMiddle(head);
        ListNode* end = reverse(middle->next);
        
        ListNode* p1 = head;
        ListNode* p2 = end;
        bool flag = true;
        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                flag = false;
                break;
            }
            else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        reverse(end);
        return flag;
    }
    ListNode* getMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
