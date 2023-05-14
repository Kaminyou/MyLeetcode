class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int maxPath = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(m, 0);
        vector<int> preDp(m, 0);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[j] = 0;
                if (j - 1 >= 0 && grid[j][i] > grid[j - 1][i - 1]) {
                    dp[j] = max(dp[j], preDp[j - 1] + 1);
                }
                if (grid[j][i] > grid[j][i - 1]) {
                    dp[j] = max(dp[j], preDp[j] + 1);
                }
                if (j + 1 < m && grid[j][i] > grid[j + 1][i - 1]) {
                    dp[j] = max(dp[j], preDp[j + 1] + 1);
                }
                if (dp[j] == i) res = max(res, dp[j]);
            }
            preDp = dp;
        }
        return res;
    }
};