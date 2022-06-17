class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
            res += dp[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = matrix[0][j];
            res += dp[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = matrix[i][j];
                if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};