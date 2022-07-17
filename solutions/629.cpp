typedef long long LL;
class Solution {
public:
    int kInversePairs(int n, int k) {
        LL mod = 1e9 + 7;
        vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (j >= i) dp[i][j] -= dp[i - 1][j - i];
                dp[i][j] = (dp[i][j] + mod) % mod;
            }
        }
        return dp[n][k] % mod;
    }
};