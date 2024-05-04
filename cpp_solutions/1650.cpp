/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* headP = p;
        Node* headQ = q;
        while (headP != headQ) {
            headP = (headP == nullptr) ? q : headP->parent;
            headQ = (headQ == nullptr) ? p : headQ->parent;
        }
        return headP;
    }
};