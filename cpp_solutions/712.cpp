class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] + static_cast<int>(s1[i - 1]);
        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + static_cast<int>(s2[j - 1]);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    int deleteS1 = dp[i - 1][j] + static_cast<int>(s1[i - 1]);
                    int deleteS2 = dp[i][j - 1] + static_cast<int>(s2[j - 1]);
                    dp[i][j] = min(deleteS1, deleteS2);
                }
            }
        }
        return dp[m][n];
    }
};