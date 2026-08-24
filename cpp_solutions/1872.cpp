class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = prefix[n] - dp[1];
        for (int i = 3; i <= n; ++i) {
            dp[i] = max(dp[i - 1], prefix[n - i + 2] - dp[i - 1]);
        }
        return dp[n];
    }
};
