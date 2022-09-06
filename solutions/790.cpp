class Solution {
public:
    int numTilings(int n) {
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        if (n == 1) return dp[n];
        dp[2] = 2;
        if (n == 2) return dp[n];
        dp[3] = 5;
        if (n == 3) return dp[n];
        for (int i = 4; i <= n; ++i) {
            dp[i] += 2 * dp[i - 1];
            dp[i] += dp[i - 3];
            dp[i] %= mod;
        }
        return dp[n];
    }
};