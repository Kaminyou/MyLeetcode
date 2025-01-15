class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN / 2)));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(0, coins[0][0]);
        for (int i = 1; i < m; ++i) {
            for (int k = 0; k < 3; ++k) {
                dp[i][0][k] = dp[i - 1][0][k] + coins[i][0];
            }
            if (coins[i][0] < 0) {
                dp[i][0][1] = max(dp[i][0][1], dp[i - 1][0][0]);
                dp[i][0][2] = max(dp[i][0][2], dp[i - 1][0][1]);
            }
        }

        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[0][j][k] = dp[0][j - 1][k] + coins[0][j];
            }
            if (coins[0][j] < 0) {
                dp[0][j][1] = max(dp[0][j][1], dp[0][j - 1][0]);
                dp[0][j][2] = max(dp[0][j][2], dp[0][j - 1][1]);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][k]) + coins[i][j];
                }
                if (coins[i][j] < 0) {
                    dp[i][j][1] = max({dp[i][j][1], dp[i][j - 1][0], dp[i - 1][j][0]});
                    dp[i][j][2] = max({dp[i][j][2], dp[i][j - 1][1], dp[i - 1][j][1]});
                }
            }
        }
        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
