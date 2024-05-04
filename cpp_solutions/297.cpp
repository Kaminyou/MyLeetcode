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


// v2
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     void serialize_(TreeNode* node, string& res) {
//         if (node == nullptr) {
//             res += "R#L";
//             return;
//         }
//         res += "R" + to_string(node->val) + "L";
//         serialize_(node->left, res);
//         serialize_(node->right, res);
//     }
//     string serialize(TreeNode* root) {
//         string res = "";
//         serialize_(root, res);
//         return res;
//     }
//     TreeNode* deserialize_(string& data, int& index) {
//         if (index == data.size()) return nullptr;
//         index++;
//         int start = index;
//         while (data[index] != 'L') index++;
//         string valStr = data.substr(start, index - start);
//         index++;
//         if (valStr == "#") return nullptr;
//         int val = stoi(valStr);
//         TreeNode* node = new TreeNode(val);
//         node->left = deserialize_(data, index);
//         node->right = deserialize_(data, index);
//         return node;
//     }
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         int index = 0;
//         TreeNode* root = deserialize_(data, index);
//         return root;
//     }
// };

// // Your Codec object will be instantiated and called as such:
// // Codec ser, deser;
// // TreeNode* ans = deser.deserialize(ser.serialize(root));