class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        int current = grid[i][j];
        int maxValue = current;
        grid[i][j] = 0;
        for (auto direction : directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] == 0) continue;
            maxValue = max(maxValue, current + dfs(grid, x, y));
        }
        grid[i][j] = current;
        return maxValue;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxValue = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                cout << "Now " << i << " " << " " << j << " " << maxValue << endl;
                maxValue = max(maxValue, dfs(grid, i, j));
            }
        }
        return maxValue;
    }
};
