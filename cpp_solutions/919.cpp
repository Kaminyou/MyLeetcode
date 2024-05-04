/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            tree.push_back(cur);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    
    int insert(int val) {
        int n = tree.size(); // insert at tree[n]
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if (n & 1) {
            tree[(n - 1) / 2]->left = node;
        }
        else {
            tree[(n - 1) / 2]->right = node;
        }
        return tree[(n - 1) / 2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */