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
    ListNode* doubleIt(ListNode* head) {
        vector<int> numbers;
        ListNode* curr = head;
        while (curr) {
            numbers.push_back(curr->val);
            curr = curr->next;
        }
        int n = numbers.size();
        int leading = 0;
        for (int i = n - 1; i >= 0; --i) {
            int tmp = numbers[i] * 2 + leading;
            numbers[i] = (tmp) % 10;
            leading = tmp / 10;
        }
        curr = head;
        for (int i = 0; i < n; ++i) {
            curr->val = numbers[i];
            curr = curr->next;
        }
        if (leading) {
            ListNode* extra = new ListNode(leading, head);
            return extra;
        }
        return head;
    }
};
