class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        
        int move = 2 * n - 2;
        for (int k = 1; k <= move; k++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int p = n - 1; p >= 0; p--) {
                    // at [i, j] and [p, q]
                    // as (i + j) == (p + q) == k
                    int j = k - i;
                    int q = k - p;
                    if (j < 0 || j >= n || q < 0 || q >= n || grid[i][j] == -1 || grid[p][q] == -1) {
                        dp[i][p] = -1;
                        continue;
                    }
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i == p ? 0 : grid[p][q]);
                }
            } 
        }
        return max(dp[n - 1][n - 1], 0);
    }
};