/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old2new;
        Node* sentinel = new Node(-1);
        Node* curr = sentinel;
        while (head) {
            curr->next = new Node(head->val);
            curr = curr->next;
            old2new[head] = curr;
            curr->random = head->random;
            head = head->next;
        }
        curr = sentinel->next;
        while (curr) {
            curr->random = old2new[curr->random];
            curr = curr->next;
        }
        return sentinel->next;
    }
};