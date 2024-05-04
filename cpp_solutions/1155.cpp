class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> dp(target + 1, 0);
        const int mod = 1e9 + 7;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<long long> dpTemp(target + 1, 0);
            for (int j = 1; j <= k; ++j) {
                for (int t = target; t >= 0; --t) {
                    if (t - j >= 0) {
                        dpTemp[t] += dp[t - j];
                        dpTemp[t] %= mod;
                    }
                }
            }
            dp = dpTemp;
        }
        return dp[target];
    }
};