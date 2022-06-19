/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
    void dfs(Node* node) {
        if (node == nullptr) return;
        if (node->left) dfs(node->left);
        
        if (!first) first = node;
        node->left = last;
        if (last) last->right = node;
        last = node;
        
        if (node->right) dfs(node->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        first->left = last;
        last->right = first;
        return first;
    }
};