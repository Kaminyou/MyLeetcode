class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        const long mod = 1e9 + 7;
        // dp[n][m][k] => len = n & max val = m & cost = k
        vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(m + 1, vector<long>(k + 1, 0)));
        
        // base case
        for (int i = 1; i <= m; ++i) dp[1][i][1] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int t = 1; t <= k; ++t) {
                    // when len = i - 1 but max = j => arr[i] can be [1,j]
                    // and not interfere with cost
                    dp[i][j][t] += j * dp[i - 1][j][t];
                    dp[i][j][t] %= mod;
                    
                    // len = i - 1 with max = curr (< j)
                    for (int curr = 1; curr < j; ++curr) {
                        dp[i][j][t] += dp[i - 1][curr][t - 1];
                        dp[i][j][t] %= mod;
                    }
                }
            }
        }
        long res = 0;
        for (int i = 1; i <= m; ++i) {
            res += dp[n][i][k];
            res %= mod;
        }
        return res;
    }
};