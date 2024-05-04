class Solution {
public:
    int getMin(int idx, vector<int>& dp, int n) {
        if (n == 1) return dp[idx];
        if (idx == 0) return min(dp[idx], dp[idx + 1]);
        else if (idx == n - 1) return min(dp[idx - 1], dp[idx]);
        else return min({dp[idx - 1], dp[idx], dp[idx + 1]});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        vector<int> dp(n, INT_MAX);
        vector<int> dpTemp(n, INT_MAX);
        for (int j = 0; j < n; ++j) {
            dp[j] = matrix[0][j];
            if (n == 1) res = min(res, dp[j]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dpTemp[j] = getMin(j, dp, n) + matrix[i][j];
                if (i == n - 1) res = min(res, dpTemp[j]);
            }
            dp = dpTemp;
        }
        return res;
    }
};