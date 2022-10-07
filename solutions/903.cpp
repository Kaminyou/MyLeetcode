class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        long long mod = 1e9 + 7;
        dp[0][0] = 1;
        s = "#" + s;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] == 'I') {
                    for (int k = 0; k < j; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
                else {
                    for (int k = j; k <= i - 1; ++k) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 0; i <= n; ++i) {
            res += dp[n][i];
            res %= mod;
        }
        return res;
    }
};