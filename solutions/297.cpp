/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void _serialize(TreeNode* node, ostringstream& out) {
        if (node == nullptr) {
            out << "# ";
            return;
        }
        out << node->val << ' ';
        _serialize(node->left, out);
        _serialize(node->right, out);
    }
    TreeNode* _deserialize(istringstream& in) {
        string token;
        in >> token;
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = _deserialize(in);
        node->right = _deserialize(in);
        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        _serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        TreeNode* node = _deserialize(in);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));