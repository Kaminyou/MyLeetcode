class Solution {
public:
    int cost(string s, int start, int end) {
        int res = 0;
        while (start < end) {
            if (s[start++] != s[end--]) ++res;
        }
        return res;
    }
    int palindromePartition(string s, int k) {
        // min change to make substring palindrome
        int n = s.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                table[i][j] = cost(s, i, j);
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = table[0][i - 1];
        }
        for (int i = 2; i <= k; ++i) {
            for (int end = n; end >= 1; --end) {
                for (int mid = 1; mid < end; ++mid) {
                    dp[end][i] = min(dp[end][i], dp[mid][i - 1] + table[mid + 1 - 1][end - 1]);
                }
            }
        }
        return dp[n][k];
    }
    
};