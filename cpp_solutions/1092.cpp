class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // longest common subsequence
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        int i = m - 1;
        int j = n - 1;
        string res;
        while (i >= 0 || j >= 0) {
            if (i < 0 ^ j < 0) {
                res += (i < 0) ? str2[j--] : str1[i--];
            }
            else if (str1[i] == str2[j]) {
                res += str1[i];
                i--;
                j--;
            }
            else {
                res += (dp[i][j + 1] > dp[i + 1][j]) ? str1[i--] : str2[j--];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};