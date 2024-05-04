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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        ListNode* current = head;
        while (current) {
            cnt++;
            current = current->next;
        }
        
        int size = cnt / k;
        int remain = cnt % k;
        vector<ListNode*> res;
        for (int i = 0; i < k; ++i) res.push_back(new ListNode());
        vector<ListNode*> temp = res;
        current = head;
        int index = 0;
        
        int count = size + ((remain > 0) ? 1 : 0);
        remain--;
        while (current) {
            temp[index]->next = new ListNode(current->val);
            temp[index] = temp[index]->next;
            count--;
            if (count == 0) {
                index++;
                count = size + ((remain > 0) ? 1 : 0);
                remain--;
            }
            current = current->next;
        }
        for (auto& node : res) node = node->next;
        return res;
        
    }
};