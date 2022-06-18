class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1e9 + 7;
        int maxPos = min(steps, arrLen);
        vector<long long> dp(maxPos, 0);
        dp[0] = 1;
        for (int i = 1; i <= steps; ++i) {
            vector<long long> dpTemp(maxPos, 0);
            for (int pos = 0; pos < maxPos; pos++) {
                dpTemp[pos] += dp[pos];
                if (pos - 1 >= 0) dpTemp[pos] += dp[pos - 1];
                if (pos + 1 < maxPos) dpTemp[pos] += dp[pos + 1];
                dpTemp[pos] %= mod;
            }
            dp = dpTemp;
        }
        return dp[0];
    }
};