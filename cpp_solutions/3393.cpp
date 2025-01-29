class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        long long mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(17, 0)));

        dp[1][1][grid[0][0]] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) continue;
                for (int p = 0; p < 16; ++p) {
                    dp[i][j][p] = dp[i - 1][j][p ^ grid[i - 1][j - 1]] + dp[i][j - 1][p ^ grid[i - 1][j - 1]];
                    dp[i][j][p] %= mod;
                }
            }
        }
        return dp[m][n][k];
    }
};


