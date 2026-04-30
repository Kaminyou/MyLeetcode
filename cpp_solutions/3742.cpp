class Solution {
public:
    int dp[200][200][401];
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = min(k + 1, m + n);
        if (k >= m + n) k = m + n; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t <= total; ++t) {
                    dp[i][j][t] = -1;
                }
            }
        }
        dp[0][0][0] = 0;

        int cost[] = {0, 1, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t <= k; ++t) {
                    if (dp[i][j][t] == -1) continue;
                    // right
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int afterCost = t + cost[val];
                        if (afterCost > k) break;
                        dp[i][j + 1][afterCost] = max(dp[i][j + 1][afterCost], dp[i][j][t] + grid[i][j + 1]);
                    }
                }
                for (int t = 0; t <= k; ++t) {
                    if (dp[i][j][t] == -1) continue;
                    // down
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int afterCost = t + cost[val];
                        if (afterCost > k) break;
                        dp[i + 1][j][afterCost] = max(dp[i + 1][j][afterCost], dp[i][j][t] + grid[i + 1][j]);
                    }
                }
            }
        }
        int res = INT_MIN;
        for (int t = 0; t <= k; ++t) {
            res = max(res, dp[m - 1][n - 1][t]);
        }
        return res == INT_MAX ? -1 : res;
    }
};
