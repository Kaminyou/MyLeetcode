class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; j < n - 2; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 2 + 1));
            }
        }
        return dp[n];
    }
};