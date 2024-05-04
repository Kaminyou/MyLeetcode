class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i <= n; ++i) dp[0][i] = 1;
        
        int mod = 1e9 + 7;
        for (int i = 1; i <= target; ++i) {
            for (int j = 1; j <= n; ++j) {
                int count = types[j - 1][0];
                int score = types[j - 1][1];
                for (int k = 0; k <= count; ++k) {
                    int preScore = i - k * score;
                    if (preScore < 0) continue;
                    dp[i][j] += dp[preScore][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[target][n];
    }
};