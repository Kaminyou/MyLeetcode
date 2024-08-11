class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
        grid[x][y] = -1;
        for (auto& direction : directions) {
            int xx = x + direction.first;
            int yy = y + direction.second;
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
            if (grid[xx][yy] != 1) continue;
            
            dfs(grid, xx, yy, m, n);
        }
    }
    bool isNotConnected(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, m, n);
                    count++;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    grid[i][j] = 1;
                }
            }
        }
        return count >= 2 || count == 0;
    }
    int minDays(vector<vector<int>>& grid) {
        if (isNotConnected(grid)) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                grid[i][j] = 0;
                if (isNotConnected(grid)) return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};
