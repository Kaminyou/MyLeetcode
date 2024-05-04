/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        Node* current = head;
        Node* next = current->next;
        Node* mark = current;
        while (next != head) {
            if (current->val <= insertVal && insertVal <= next->val) break;
            if (current->val > next->val && (insertVal >= current->val || insertVal <= next->val)) break;
            current = current->next;
            next = next->next;
        }
        current->next = new Node(insertVal, next);
        return head;
    }
};