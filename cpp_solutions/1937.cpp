class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> dp(n, 0);
        vector<long long> precompute(n, 0);
        
        for (int j = 0; j < n; ++j) dp[j] = points[0][j];
        
        for (int i = 1; i < m; ++i) {
            // precompute the previous layer
            // forward pass
            precompute[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                precompute[j] = max(dp[j], precompute[j - 1] - 1);
            }
            // backward pass
            precompute[n - 1] = max(precompute[n - 1], dp[n - 1]);
            for (int j = n - 2; j >= 0; --j) {
                precompute[j] = max(precompute[j], precompute[j + 1] - 1);
            }
            
            for (int j = 0; j < n; ++j) {
                dp[j] = points[i][j] + precompute[j];
            }
        }
        long long res = 0;
        for (int j = 0; j < n; ++j) res = max(res, dp[j]);
        return res;
    }
};