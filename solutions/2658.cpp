class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(int i, int j, vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        count += grid[i][j];
        grid[i][j] = 0;
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                if (grid[nextX][nextY] == 0) continue;
                q.push({nextX, nextY});
                count += grid[nextX][nextY];
                grid[nextX][nextY] = 0;
            }
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) count = max(count, bfs(i, j, grid));
            }
        }
        return count;
    }
};