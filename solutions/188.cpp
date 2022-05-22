class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int n = prices.size();
        int operation = 2 * k + 1;
        vector<vector<int>> dp(n, vector<int>(operation + 1, 0));
        for (int i = 1; i < operation; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j < operation; j++) {
                if (j & 1) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
        int res = 0;
        for (int i = 2; i < operation; i += 2) {
            res = max(res, dp[n - 1][i]);
        } 
        return res;
    }
};