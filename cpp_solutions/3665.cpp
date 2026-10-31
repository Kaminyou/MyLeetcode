class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));
        dp[0][0] = {1, 0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == 0) {
                    if (i - 1 >= 0) {
                        if (grid[i - 1][j] == 0) dp[i][j].first += dp[i - 1][j].first;
                        if (grid[i - 1][j] == 1) dp[i][j].first += dp[i - 1][j].second;
                    }
                    if (j - 1 >= 0) {
                        if (grid[i][j - 1] == 0) dp[i][j].first += dp[i][j - 1].first;
                        if (grid[i][j - 1] == 1) dp[i][j].first += dp[i][j - 1].first;
                    }
                }
                if (grid[i][j] == 1) {
                    if (i - 1 >= 0) {
                        if (grid[i - 1][j] == 0) dp[i][j].first += dp[i - 1][j].first;
                        if (grid[i - 1][j] == 1) dp[i][j].first += dp[i - 1][j].second;
                    }
                    if (j - 1 >= 0) {
                        if (grid[i][j - 1] == 0) dp[i][j].second += dp[i][j - 1].first;
                        if (grid[i][j - 1] == 1) dp[i][j].second += dp[i][j - 1].first;
                    }
                }
                dp[i][j].first %= mod;
                dp[i][j].second %= mod;
            }
        }
        return dp[m - 1][n - 1].first;
    }
};

