class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m * n);
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int newIdx = (i * n + j + k) % (m * n);
                int newI = newIdx / n;
                int newJ = newIdx % n;
                res[newI][newJ] = grid[i][j];
            }
        }
        return res;
    }
};

