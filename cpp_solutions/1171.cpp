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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* cur = sentinel;
        
        unordered_map<int, ListNode*> mp;
        int currentSum = 0;
        while (cur) {
            currentSum += cur->val;
            if (mp.find(currentSum) != mp.end()) {
                int tempSum = currentSum;
                cur = mp[currentSum]->next;
                tempSum += cur->val;
                while (tempSum != currentSum) {
                    mp.erase(tempSum);
                    ListNode* temp = cur;
                    cur = cur->next;
                    tempSum += cur->val;
                }
                mp[currentSum]->next = cur->next;
                cur = cur->next;
            }
            else {
                mp[currentSum] = cur;
                cur = cur->next;
            }
            
        }
        return sentinel->next;
    }
};