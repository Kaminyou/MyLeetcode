class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> positive(m, vector<int>(n, 0));
        vector<vector<int>> negative(m, vector<int>(n, 0));
        
        for (int j = 0; j < n; ++j) {
            positive[m - 1][j] = grid[m - 1][j];
            negative[0][j] = grid[0][j];
        }
        
        for (int i = m - 2; i >= 0; --i) {
            positive[i][0] = grid[i][0];
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j]) positive[i][j] = min({positive[i + 1][j - 1], positive[i + 1][j], positive[i + 1][j + 1]}) + 1;
            }
            positive[i][n - 1] = grid[i][n - 1];
        }
        
        for (int i = 1; i < m; ++i) {
            negative[i][0] = grid[i][0];
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j]) negative[i][j] = min({negative[i - 1][j - 1], negative[i - 1][j], negative[i - 1][j + 1]}) + 1;
            }
            negative[i][n - 1] = grid[i][n - 1];
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (positive[i][j]) res += positive[i][j] - 1;
                if (negative[i][j]) res += negative[i][j] - 1;
            }
        }
        return res;
    }
};