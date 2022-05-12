class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // horizontal, vertical, diagonal, antidiagonal
        vector<vector<int>> dp(n, vector<int>(4, 0));
        vector<vector<int>> tempDP(n, vector<int>(4, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) tempDP[j][0] = tempDP[j][1] = tempDP[j][2] = tempDP[j][3] = 0;
                else {
                    tempDP[j][0] = (j == 0 ? 1 : tempDP[j - 1][0] + mat[i][j]);
                    tempDP[j][1] = dp[j][1] + mat[i][j];
                    tempDP[j][2] = (j == 0 ? 1 : dp[j - 1][2] + mat[i][j]);
                    tempDP[j][3] = (j == n - 1 ? 1 : dp[j + 1][3] + mat[i][j]);
                    res = max({res, tempDP[j][0], tempDP[j][1], tempDP[j][2], tempDP[j][3]});
                }
            }
            dp = tempDP;
        }
        return res;
    }
};