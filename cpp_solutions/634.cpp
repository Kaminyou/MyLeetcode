class Solution {
public:
    int findDerangement(int n) {
        if (n == 1) return 0;
        const long long mod = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
        }
        return dp[n];
    }
};