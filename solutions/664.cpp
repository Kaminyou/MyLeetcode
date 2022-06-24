class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (i == j) ? 1 : dp[i + 1][j] + 1;
                // e.g.,
                // abcdcef  => abc[d][cef] suppose ab[cccef] => ab[c[d]cef]
                //   ^ ^ ^       ^    ^ ^
                //   i k j       i    k j
                for (int k = i + 1; k <= j; ++k) {
                    if (s[i] == s[k]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};