class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m - 1][n - 1] = (dungeon[m - 1][n - 1] >= 0) ? 1 : 1 - dungeon[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--) {
            if (dungeon[i][n - 1] >= 0) dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
            else dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
        }
        
        for (int j = n - 2; j >= 0; j--) {
            if (dungeon[m - 1][j] >= 0) dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
            else dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
        }
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (dungeon[i][j] >= 0) {
                    int right = max(1, dp[i + 1][j] - dungeon[i][j]);
                    int down = max(1, dp[i][j + 1] - dungeon[i][j]);
                    dp[i][j] = min(right, down);
                }
                else {
                    int right = dp[i + 1][j] - dungeon[i][j];
                    int down = dp[i][j + 1] - dungeon[i][j];
                    dp[i][j] = min(right, down);
                }
            }
        }
        return dp[0][0];
    }
};