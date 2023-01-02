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
    ListNode* removeNodes(ListNode* head) {
        ListNode* sentinel = new ListNode(INT_MAX, head);
        stack<ListNode*> st;
        st.push(sentinel);
        
        while (head) {
            while (!st.empty() && head->val > st.top()->val) {
                st.pop();
            }
            st.top()->next = head;
            st.push(head);
            head = head->next;
        }

        return sentinel->next;
    }
};