class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string s = to_string(grid[i][j]);
                int length = s.size();
                ans[j] = max(ans[j], length);
            }
        }
        return ans;
    }
};