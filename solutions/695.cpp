class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        int res = 1;
        for (auto& direction : directions) {
            int xNext = x + direction.first;
            int yNext = y + direction.second;
            if (xNext < 0 || xNext >= M || yNext < 0 || yNext >= N) continue;
            if (grid[xNext][yNext] == 0) continue;
            res += dfs(xNext, yNext, grid);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        M = grid.size();
        N = grid[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(i, j, grid));
                }
            }
        }
        return res;
    }
};