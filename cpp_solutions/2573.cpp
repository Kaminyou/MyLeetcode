class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '0');
        char c = 'a';
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (c > 'z') return "";
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0) s[j] = c;
                }
                c++;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }
        return s;
    }
};

