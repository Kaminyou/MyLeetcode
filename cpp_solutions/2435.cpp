class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(k, 0)));
        long long mod = 1e9 + 7;
        
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int i = 1; i < m; ++i) {
            int shift = grid[i][0] % k;
            for (int t = 0; t < k; ++t) {
                int target = (t - shift + k) % k;
                dp[i][0][t] = dp[i - 1][0][target];
                dp[i][0][t] %= mod;
            }
        }
        for (int j = 1; j < n; ++j) {
            int shift = grid[0][j] % k;
            for (int t = 0; t < k; ++t) {
                dp[0][j][t] = dp[0][j - 1][(t - shift + k) % k];
                dp[0][j][t] %= mod;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int shift = grid[i][j] % k;
                for (int t = 0; t < k; ++t) {
                    // from top
                    dp[i][j][t] += dp[i - 1][j][(t - shift + k) % k];
                    // from left
                    dp[i][j][t] += dp[i][j - 1][(t - shift + k) % k];
                    
                    dp[i][j][t] %= mod;
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};