class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        // i start from zero
        // => dp[0][2] == dp[0][0] like "a*"
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // dp[i][j] = dp[i][j - 2] => zero time
                    // (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') =>
                    // one time up
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
