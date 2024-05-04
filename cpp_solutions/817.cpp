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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        
        ListNode* current = head;
        bool consecutive = false;
        while (current) {
            if (st.find(current->val) != st.end()) {
                if (!consecutive) res++;
                consecutive = true;
            }
            else consecutive = false;
            current = current->next;
        }
        return res;
    }
};
