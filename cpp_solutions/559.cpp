/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int res = 0;
    void recursive(Node* node, int level) {
        if (node == nullptr) return;
        res = max(res, level);
        for (auto neighbor : node->children) {
            recursive(neighbor, level + 1);
        }
    }
    int maxDepth(Node* root) {
        recursive(root, 1);
        return res;
    }
};