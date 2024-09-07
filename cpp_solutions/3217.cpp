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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* sentinel = new ListNode(-1, head);
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* cur = sentinel;
        while (cur) {
            while (cur->next && st.count(cur->next->val)) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return sentinel->next;
    }
};
