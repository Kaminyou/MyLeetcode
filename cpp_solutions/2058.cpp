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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = -1;
        int current = -1;
        vector<int> criticals;
        int index = 0;
        while (head) {
            if (prev != -1 && current != -1) {
                if (current > prev && current > head->val) {
                    criticals.push_back(index);
                }
                else if (current < prev && current < head->val) {
                    criticals.push_back(index);
                }
            }
            prev = current;
            current = head->val;
            head = head->next;
            index++;
        }
        int n = criticals.size();
        if (n < 2) {
            return {-1, -1};
        }
        
        int maxDistance = criticals[n - 1] - criticals[0];
        int minDistance = maxDistance;
        for (int i = 0; i < n - 1; ++i) {
            minDistance = min(minDistance, criticals[i + 1] - criticals[i]);
        }
        return {minDistance, maxDistance};
    }
};
