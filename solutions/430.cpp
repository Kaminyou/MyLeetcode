/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    vector<Node*> recursive(Node* node) {
        Node* prev = nullptr;
        Node* curr = node;
        if (curr == nullptr) return {node, node};
        Node* next = node->next;
        while (curr) {
            if (curr->child != nullptr) {
                vector<Node*> middle = recursive(curr->child);
                Node* middleStart = middle[0];
                Node* middleEnd = middle[1];
                curr->next = middleStart;
                middleStart->prev = curr;
                middleEnd->next = next;
                curr->child = nullptr;
                if (next == nullptr) {
                    return {node, middleEnd};
                }
                else next->prev = middleEnd;
            }
            prev = curr;
            curr = next;
            if (next != nullptr) next = next->next;
        }
        return {node, prev};
    }
    Node* flatten(Node* head) {
        return recursive(head)[0];
    }
};