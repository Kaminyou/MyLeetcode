/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* _cloneGraph(Node* node, unordered_map<Node*, Node*>& mp) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];

        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        vector<Node*> newNeighbors;
        for (auto& neighbor : node->neighbors) {
            newNeighbors.push_back(_cloneGraph(neighbor, mp));
        }
        newNode->neighbors = newNeighbors;
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return _cloneGraph(node, mp);
    }
};