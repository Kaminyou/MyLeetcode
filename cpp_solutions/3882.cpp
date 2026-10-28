class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> dp(m * n, vector<bool>(1024, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int gridVal = grid[i][j];
                if (i == 0 && j == 0) dp[i * n + j][gridVal] = true;
                else {
                    if (i - 1 >= 0) {
                        for (int k = 0; k < 1024; ++k) {
                            if (dp[(i - 1) * n + j][k]) {
                                int val = gridVal ^ k;
                                dp[i * n + j][val] = true;
                            }
                        }
                    }
                    if (j - 1 >= 0) {
                        for (int k = 0; k < 1024; ++k) {
                            if (dp[i * n + j - 1][k]) {
                                int val = gridVal ^ k;
                                dp[i * n + j][val] = true;
                            }
                        }
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int k = 0; k < 1024; ++k) {
            if (dp[m * n - 1][k]) res = min(res, k);
        }
        return res;
    }
};

