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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        int accum = 0;
        while (head) {
            if (head->val == 0) {
                v.push_back(accum);
                accum = 0;
            }
            else {
                accum += head->val;
            }
            head = head->next;
        }
        ListNode* sentinel = new ListNode(0);
        ListNode* current = sentinel;
        int n = v.size();
        for (int i = 1; i < n; ++i) {
            current->next = new ListNode(v[i]);
            current = current->next;
        }
        return sentinel->next;
    }
};
