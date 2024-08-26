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
    void traverse(Node* node, vector<int>& res) {
        if (node) {
            for (auto& child : node->children) {
                traverse(child, res);
            }
            res.push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
};
