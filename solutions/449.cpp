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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize_(root, res);
        return res;
    }
    void serialize_(TreeNode* node, string& res) {
        if (node == nullptr) return;
        char buf[4];
        memcpy(buf, &(node->val), sizeof(int));
        for (int i = 0; i < 4; ++i) res.push_back(buf[i]);
        serialize_(node->left, res);
        serialize_(node->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize_(data, pos, INT_MIN, INT_MAX);
    }
    TreeNode* deserialize_(string& data, int& pos, int minVal, int maxVal) {
        if (pos >= data.size()) return nullptr;
        int value;
        memcpy(&value, &(data[pos]), sizeof(int));
        if (value < minVal || value > maxVal) return nullptr;
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = deserialize_(data, pos, minVal, value);
        node->right = deserialize_(data, pos, value, maxVal);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;