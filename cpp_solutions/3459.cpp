class Solution {
public:
    int memo[501][501][4][2];
    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        res = max(res, dfs(grid, i, j, k, 1));
                    }
                }
            }
        }
        return res;
    }
    bool isBound(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    bool valid(int a, int b) {
        if (a == 1) return b == 2;
        if (a == 0) return b == 2;
        if (a == 2) return b == 0;
        return false;
    }
    int dfs(vector<vector<int>>& grid, int x, int y, int k, int t) {
        if (memo[x][y][k][t] != 0) return memo[x][y][k][t];
        int res = 1;
        int xx = x + directions[k].first;
        int yy = y + directions[k].second;
        if (isBound(grid, xx, yy) && valid(grid[x][y], grid[xx][yy])) {
            res = max(res, 1 + dfs(grid, xx, yy, k, t));
        }
        if (t == 1) {
            int kk = (k + 1) % 4;
            int xx = x + directions[kk].first;
            int yy = y + directions[kk].second;
            if (isBound(grid, xx, yy) && valid(grid[x][y], grid[xx][yy])) {
                res = max(res, 1 + dfs(grid, xx, yy, kk, t - 1));
            }
        }
        return memo[x][y][k][t] = res;
    }
};
