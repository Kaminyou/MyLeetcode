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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* sentinel = new ListNode(0, head);
        ListNode* slow = sentinel;
        ListNode* fast = sentinel;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return sentinel->next;
    }
};
// s 0 1 2 3 4 5 6 e
// ^ 
// ^
// s 0 1 2 3 4 5 6 e
//   ^ 
//     ^
// s 0 1 2 3 4 5 6 e
//     ^ 
//         ^
// s 0 1 2 3 4 5 6 e
//       ^ 
//             ^
// s 0 1 2 3 4 5 6 e
//         ^ 
//                 ^

// s 0 1 e
// ^ 
// ^
// s 0 1 e
//   ^ 
//     ^