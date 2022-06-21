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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int, pair<int, ListNode*>>, vector<pair<int, pair<int, ListNode*>>>, greater<pair<int, pair<int, ListNode*>>>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(make_pair(lists[i]->val, make_pair(i, lists[i])));
                lists[i] = lists[i]->next;
            }
        }
        ListNode* sentinel = new ListNode();
        ListNode* curr = sentinel;
        while (!pq.empty()) {
            auto [num, complex] = pq.top();
            auto [l, node] = complex;
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (lists[l] != nullptr) {
                pq.push(make_pair(lists[l]->val, make_pair(l, lists[l])));
                lists[l] = lists[l]->next;
            }
        }
        return sentinel->next;
    }
};