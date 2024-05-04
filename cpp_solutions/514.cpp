class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        // dp[i][j]: complete key[i:] with ring starting from j
        vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) dp[m][i] = 0;
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // rot j -> k
                    if (key[i] == ring[k]) {
                        int diff = abs(j - k);
                        diff = min(diff, n - diff);
                        dp[i][j] = min(dp[i][j], dp[i + 1][k] + diff);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};