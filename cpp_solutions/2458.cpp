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
    vector<int> heights;
    vector<int> depths;
    unordered_map<int, vector<int>> d2hs;
    
    int depthDfs(TreeNode* node, int depth) {
        if (node == nullptr) return -1;
        int left = depthDfs(node->left, depth + 1);
        int right = depthDfs(node->right, depth + 1);
        
        heights[node->val] = max(left, right) + 1;
        depths[node->val] = depth;
        d2hs[depth].push_back(max(left, right) + 1);
        return max(left, right) + 1;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        heights.resize(100001, -1);
        depths.resize(100001, -1);
        depthDfs(root, 0);
        for (auto& [d, hs] : d2hs) {
            sort(hs.begin(), hs.end(), greater<int>());
        }
        int m = queries.size();
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            int depth = depths[queries[i]];
            int height = heights[queries[i]];
            
            if (d2hs[depth].size() == 1) {
                res[i] = depth - 1;
            }
            else if (d2hs[depth][0] == height) {
                res[i] = d2hs[depth][1] + depth;
            }
            else {
                res[i] = d2hs[depth][0] + depth;
            }
        }
        return res;
    }
};