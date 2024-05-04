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
    TreeNode* dfs(string& s, int& index) {
        if (index >= s.size() || s[index] == ')') return nullptr;
        
        int start = index;
        while (index + 1 < s.size() && s[index + 1] != '(' && s[index + 1] != ')') index++;
        string temp = s.substr(start, index - start + 1);
        TreeNode* node = new TreeNode(stoi(temp));
        index++;
        
        if (index < s.size() && s[index] == '(') {
            index++;
            node->left = dfs(s, index);
            index++;
        }
        if (index < s.size() && s[index] == '(') {
            index++;
            node->right = dfs(s, index);
            index++;
        }
        return node;
    }
    TreeNode* str2tree(string s) {
        int index = 0;
        return dfs(s, index);
    }
};