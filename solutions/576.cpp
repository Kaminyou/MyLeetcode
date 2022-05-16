class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        long long count = 0;
        const long long mod = 1e9 + 7;
        for (int k = 0; k < maxMove; k++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == 0) count += dp[i][j];
                    if (i == m - 1) count += dp[i][j] ;
                    if (j == 0) count += dp[i][j];
                    if (j == n - 1) count += dp[i][j];
                    if (i > 0) temp[i][j] += dp[i - 1][j];
                    temp[i][j] %= mod;
                    if (i < m - 1) temp[i][j] += dp[i + 1][j];
                    temp[i][j] %= mod;
                    if (j > 0) temp[i][j] += dp[i][j - 1];
                    temp[i][j] %= mod;
                    if (j < n - 1) temp[i][j] += dp[i][j + 1];
                    temp[i][j] %= mod;
                    count %= mod;
                }
            }
            dp = temp;
        }
        return count % mod;
    }
};