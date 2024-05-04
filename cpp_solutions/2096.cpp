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
    string startPath;
    string destPath;
    void dfs(TreeNode* node, string& path, int startValue, int destValue) {
        if (node == nullptr) return;
        if (node->val == startValue) {
            startPath = path;
        }
        if (node->val == destValue) {
            destPath = path;
        }
        path.push_back('L');
        dfs(node->left, path, startValue, destValue);
        path.pop_back();
        
        path.push_back('R');
        dfs(node->right, path, startValue, destValue);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        dfs(root, path, startValue, destValue);
        
        int minPathLen = min(startPath.size(), destPath.size());
        int index = 0;
        for (int i = 0; i < minPathLen; ++i) {
            if (startPath[i] != destPath[i]) {
                break;
            }
            index++;
        }
        string res = "";
        for (int i = startPath.size() - 1; i >= index; i--) {
            res += 'U';
        }
        for (int i = index; i < destPath.size(); i++) {
            res += destPath[i];
        }
        return res;
    }
};