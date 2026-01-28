class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        map<int, vector<pair<int, int>>, greater<int>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[grid[i][j]].push_back({i, j});
            }
        }
        vector<vector<pair<int, int>>> orderedCells(mp.size());
        int index = 0;
        for (auto& [k, vs] : mp) {
            for (auto& v : vs) orderedCells[index].push_back(v);
            index++;
        }

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
        for (int t = 0; t <= k; ++t) {
            int minVal = INT_MAX;
            for (auto& cells : orderedCells) {
                for (auto& cell : cells) {
                    minVal = min(minVal, dp[cell.first][cell.second]);
                }
                for (auto& cell : cells) {
                    dp[cell.first][cell.second] = minVal;
                }
            }

            dp[0][0] = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
