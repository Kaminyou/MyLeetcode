class Solution {
public:
    bool isMagicSquare(int i, int j, vector<vector<int>>& grid) {
        vector<bool> hash(16, false);
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                hash[grid[i + ii][j + jj]] = true;
            }
        }
        int cnt = 0;
        for (int k = 1; k <= 9; ++k) cnt += hash[k];
        if (cnt != 9) return false;
        
        if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15) return false;
        if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != 15) return false;
        if (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15) return false;
        if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15) return false;
        if (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != 15) return false;
        if (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15) return false;
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15) return false;
        if (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != 15) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                res += isMagicSquare(i, j, grid);
            }    
        }
        return res;
    }
};