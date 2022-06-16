class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size() != m + n) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= m + n; ++i) {
            for (int j = 0; j <= min(i, m); ++j) {
                int k = i - j;
                if (k < 0 || k > n) continue;
                if (j > 0 && s1[j - 1] == s3[i - 1]) dp[j][k] = max(dp[j][k], dp[j - 1][k]);
                if (k > 0 && s2[k - 1] == s3[i - 1]) dp[j][k] = max(dp[j][k], dp[j][k - 1]);
            }
        }
        return dp[m][n];
    }
};