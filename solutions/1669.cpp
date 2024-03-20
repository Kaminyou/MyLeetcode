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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int index = 1;
        ListNode* current = list1;
        ListNode* from = nullptr;
        ListNode* to = nullptr;
        while (current) {
            if (index == a) from = current;
            if (index == b + 2) to = current;
            index++;
            current = current->next;
            if (to) break;
        }
        from->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = to;
        return list1;
    }
};
