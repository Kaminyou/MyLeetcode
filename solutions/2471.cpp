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
    int findMinSwap(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> vec(n);

        for(int i = 0; i < n; i++) {
            vec[i].first = arr[i];
            vec[i].second = i;
        }

        sort(vec.begin(), vec.end());

        int ans=0, c=0, j;

        for(int i = 0; i < n; i++) {  
            if (vec[i].second == i)
                continue;
            else {
                swap(vec[i].first, vec[vec[i].second].first);
                swap(vec[i].second, vec[vec[i].second].second);
            }

            if(i != vec[i].second) --i;
            ans++;
        }

        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res += findMinSwap(level);
        }
        return res;
    }
};