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
class Solution {
public:
    void getPredecessor(stack<TreeNode*>& pre) {
        TreeNode* t = pre.top();
        pre.pop();
        t = t->left;
        if (t) {
            pre.push(t);
            t = t->right;
            while (t) {
                pre.push(t);
                t = t->right;
            }
        }
    }
    void getSuccessor(stack<TreeNode*>& suc) {
        TreeNode* t = suc.top();
        suc.pop();
        t = t->right;
        if (t) {
            suc.push(t);
            t = t->left;
            while (t) {
                suc.push(t);
                t = t->left;
            }
        }
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pre;
        stack<TreeNode*> suc;
        
        vector<int> res;
        while (root) {
            if (root->val >= target) {
                suc.push(root);
                root = root->left;
            }
            else {
                pre.push(root);
                root = root->right;
            }
        }
        
        while (k--) {
            if (!pre.empty() && !suc.empty()) {
                if (target - pre.top()->val < suc.top()->val - target) {
                    res.push_back(pre.top()->val);
                    getPredecessor(pre);
                }
                else {
                    res.push_back(suc.top()->val);
                    getSuccessor(suc);
                }
            }
            else if (!pre.empty()) {
                res.push_back(pre.top()->val);
                getPredecessor(pre);
            }
            else {
                res.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        return res;
    }
};