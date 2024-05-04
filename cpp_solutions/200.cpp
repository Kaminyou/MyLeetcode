class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        for (auto& direction : directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
            dfs(grid, x, y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};