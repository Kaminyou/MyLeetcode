class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(k * 2 + 1, 0);
        for (int i = 0; i < k; ++i) dp[i * 2 + 1] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            vector<int> dpTemp(k * 2 + 1, 0);
            dpTemp[0] = 0;
            for (int j = 0; j < k; ++j) {
                dpTemp[j * 2 + 1] = max(dp[j * 2 + 1], dp[j * 2] - prices[i]);
                dpTemp[j * 2 + 2] = max(dp[j * 2 + 2], dp[j * 2 + 1] + prices[i]);
            }
            dp = dpTemp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};