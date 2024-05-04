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

class Codec {
public:
    // Encodes a tree to a single string.
    void _serialize(Node* node, string& s) {
        if (node == nullptr) s.push_back('#');
        else {
            int value = node->val;
            int size = node->children.size();
            s += to_string(value) + " " + to_string(size) + " ";
            for (auto child : node->children) {
                _serialize(child, s);
            }
        }
    }
    string serialize(Node* root) {
        string s = "";
        _serialize(root, s);
        return s;
    }
	
    Node* _deserialize(stringstream& ss) {
        string value;
        string size;
        ss >> value;
        if (value == "#") return nullptr;
        Node* node = new Node(stoi(value));
        ss >> size;
        for (int i = 0; i < stoi(size); i++) {
            node->children.push_back(_deserialize(ss));
        }
        return node;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return _deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));