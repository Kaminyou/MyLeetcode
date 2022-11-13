class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n; ++i) {
                int end = i + length - 1;
                if (end >= n) break;
                if (s[i] == s[end]) {
                    if (i + 1 == end) dp[i][end] = true;
                    else dp[i][end] = dp[i + 1][end - 1];
                }
            }
        }
        vector<int> setDp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            setDp[i] = setDp[i - 1];
            for (int j = 1; j <= i; ++j) {
                if (dp[j - 1][i - 1] && i - j + 1 >= k) setDp[i] = max(setDp[i], setDp[j - 1] + 1);
            }
        }
        return setDp[n];
    }
};
      