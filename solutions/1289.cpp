class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n, 0);
        vector<int> dpTemp(n, 0);
        for (int j = 0; j < n; ++j) dp[j] = grid[0][j];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dpTemp[j] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (j == k) continue;
                    dpTemp[j] = min(dpTemp[j], dp[k] + grid[i][j]);
                }
            }
            dp = dpTemp;
        }
        
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[j]);
        }
        return res;
    }
};