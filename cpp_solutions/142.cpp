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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* current = head;
        while (current) {
            if (st.count(current)) return current;
            st.insert(current);
            current = current->next;
        }
        return nullptr;
    }
};