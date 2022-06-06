class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); ++k) {
            int g = group[k];
            int p = profit[k];
            for (int i = minProfit; i >= 0; i--) {
                for (int j = n - g; j >= 0; j--) {
                    dp[min(i + p, minProfit)][j + g] = (dp[min(i + p, minProfit)][j + g] + dp[i][j]) % mod;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= n; ++i) res = (res + dp[minProfit][i]) % mod;
        return res;
    }
};