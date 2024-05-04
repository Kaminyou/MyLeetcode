class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int rowCount = 0;
        vector<int> colCounts(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // reset rowCount
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowCount = 0;
                    for (int k = j; k < n; k++) {
                        if (grid[i][k] == 'E') rowCount++;
                        if (grid[i][k] == 'W') break;
                    }
                }
                // reset colCounts
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colCounts[j] = 0;
                    for (int k = i; k < m; k++) {
                        if (grid[k][j] == 'E') colCounts[j]++;
                        if (grid[k][j] == 'W') break;
                    }
                }
                
                // count
                if (grid[i][j] == '0') {
                    res = max(res, rowCount + colCounts[j]);
                }
            }
        }
        return res;
    }
};