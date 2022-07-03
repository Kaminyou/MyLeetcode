class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n, vector<long long>(forget, 0));
        dp[0][0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = forget - 1; j >= 1; j--) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            for (int j = delay; j < forget; ++j) {
                dp[i][0] += dp[i][j];
                dp[i][0] %= mod;
            }
        }
        long long sum = 0;
        for (int j = 0; j < forget; ++j) {
            sum += dp[n - 1][j];
            sum %= mod;
        }
        return sum;
    }
};