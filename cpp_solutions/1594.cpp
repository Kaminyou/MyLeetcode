class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long mod = 1e9 + 7;
        vector<vector<long long>> minDP(m, vector<long long>(n, INT_MAX));
        vector<vector<long long>> maxDP(m, vector<long long>(n, INT_MIN));
        minDP[0][0] = grid[0][0];
        maxDP[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    minDP[i][j] = min(minDP[i][j], minDP[i - 1][j] * grid[i][j]);
                    minDP[i][j] = min(minDP[i][j], maxDP[i - 1][j] * grid[i][j]);

                    maxDP[i][j] = max(maxDP[i][j], minDP[i - 1][j] * grid[i][j]);
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i - 1][j] * grid[i][j]);
                }
                if (j - 1 >= 0) {
                    minDP[i][j] = min(minDP[i][j], minDP[i][j - 1] * grid[i][j]);
                    minDP[i][j] = min(minDP[i][j], maxDP[i][j - 1] * grid[i][j]);

                    maxDP[i][j] = max(maxDP[i][j], minDP[i][j - 1] * grid[i][j]);
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][j - 1] * grid[i][j]);
                }
            }
        }
        return max(maxDP[m - 1][n - 1], (long long)-1) % mod;
    }
};

