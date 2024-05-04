class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += grid[i][0];
            res += grid[i][n - 1];
            for (int j = 1; j < n; ++j) {
                res += abs(grid[i][j] - grid[i][j - 1]);
            }
        }
        
        for (int j = 0; j < n; ++j) {
            res += grid[0][j];
            res += grid[n - 1][j];
            for (int i = 1; i < n; ++i) {
                res += abs(grid[i][j] - grid[i - 1][j]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) res += 2;
            }
        }
        return res;
    }
};
