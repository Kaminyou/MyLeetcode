class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        long long dp[k + 1][3];

        for (int t = 0; t < 3; ++t) dp[0][t] = 0;
        for (int j = 1; j <= k; ++j) {
            dp[j][0] = 0;
            dp[j][1] = -prices[0];
            dp[j][2] = prices[0];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                dp[j][0] = max({dp[j][0], dp[j][1] + prices[i], dp[j][2] - prices[i]});
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
                dp[j][2] = max(dp[j][2], dp[j - 1][0] + prices[i]);
            }
        }
        return dp[k][0];
    }
};

