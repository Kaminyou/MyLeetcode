class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<char>> edge(n, vector<char>(n));
        for (int len = 2; len <= n; ++len) {
            for (int left = 0, right = len - 1; right < n; ++left, ++right) {
                if (s[left] == s[right] && (len == 2 || s[left] != edge[left + 1][right - 1])) {
                    dp[left][right] = dp[left + 1][right - 1] + 2; 
                    edge[left][right] = s[left];
                }
                else if (dp[left + 1][right] > dp[left][right - 1]) {
                    dp[left][right] = dp[left + 1][right];
                    edge[left][right] = edge[left + 1][right];
                }
                else {
                    dp[left][right] = dp[left][right - 1];
                    edge[left][right] = edge[left][right - 1];
                }
            }
        }
        return dp[0][n - 1];
    }
};