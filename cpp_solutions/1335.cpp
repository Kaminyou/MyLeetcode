class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= min(i, d); ++k) {
                int maxVal = 0;
                for (int j = i; j >= k; --j) {
                    maxVal = max(maxVal, jobDifficulty[j - 1]);
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + maxVal);
                }
            }
        }
        if (dp[n][d] == INT_MAX / 2) return -1;
        return dp[n][d];
    }
};
