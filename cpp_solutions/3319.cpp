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
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    pair<int, int> isPerfect(TreeNode* node, int k) { // level, nodes
        if (node == nullptr) return {0, 0};
        int cnt = 1;
        pair<int, int> left = isPerfect(node->left, k);
        pair<int, int> right = isPerfect(node->right, k);
        int level = max(left.first, right.first) + 1;
        cnt += left.second;
        cnt += right.second;
        bool perfect = true;
        if ((1 << level) - 1 != cnt) perfect = false;
        if (perfect) {
            pq.push(cnt);
        }
        
        while (pq.size() > k) pq.pop();
        return {level, cnt};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        isPerfect(root, k);
        if (pq.size() < k) return -1;
        int res = pq.top();
        return res;
    }
};

