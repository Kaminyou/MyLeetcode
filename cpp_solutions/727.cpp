class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        // dp[i][j]: the starting index of the substring where T has length i and S has length j.
        // if T[i - 1] == S[j - 1], this means we could borrow the start index from dp[i - 1][j - 1] to make the current substring valid;
        // else, we only need to borrow the start index from dp[i][j - 1] which could either exist or not.

        vector<vector<int>> dp(m + 1, vector(n + 1, -1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        
        int minLen = INT_MAX;
        int start = -1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > i) continue;
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else dp[i][j] = dp[i - 1][j];
            }
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }
        if (start == -1) return "";
        return s1.substr(start, minLen);
    }
};