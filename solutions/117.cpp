/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* dummy = new Node(-1); // linked list for next level 
        Node* head = root;
        Node* curr = dummy;
        while (root) {
            if (root->left) {
                curr->next = root->left;
                curr = curr->next;
            }
            if (root->right) {
                curr->next = root->right;
                curr = curr->next;
            }
            root = root->next;
            
            // go to next level
            if (!root) {
                curr = dummy;
                root = dummy->next;
                dummy->next = nullptr;
            }
        }
        return head;
    }
};