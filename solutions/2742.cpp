class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        // each paid painter cost cost[i] and can paint 1 + time[i] walls
        // 1 + time[i] means himself + free workers
        int n = cost.size();
        cost.insert(cost.begin(), 0);
        time.insert(time.begin(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
        
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i + 1][min(n, j + 1 + time[i + 1])] = min(dp[i + 1][min(n, j + 1 + time[i + 1])], dp[i][j] + cost[i + 1]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
        return dp[n][n];
    }
};
