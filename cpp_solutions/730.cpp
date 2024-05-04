class Solution {
public:
    int countPalindromicSubsequences(string s) {
        long long mod = 1e9 + 7;
        int n = s.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n; ++i) {
                int j = i + length - 1;
                if (j >= n) break;
                if (s[i] == s[j]) {
                    int left = i + 1;
                    int right = j - 1;
                    while (left <= right && s[i] != s[left]) left++;
                    while (left <= right && s[j] != s[right]) right--;
                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    }
                    else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                }
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] += mod;
                dp[i][j] %= mod;
            }
        }
        return dp[0][n - 1];
    }
};