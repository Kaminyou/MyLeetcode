class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inorder(n + 2, 0);
        for (auto& edge : edges) {
            inorder[edge[0]] += 1;
            inorder[edge[1]] += 1;
        }
        for (int i = 1; i <= n + 1; ++i) {
            if (inorder[i] == n) return i;
        }
        return -1;
    }
};
