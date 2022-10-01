class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool bfs(int i, int j, vector<vector<int>>& grid) {
        bool res = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) {
                    res = false;
                    continue;
                }
                if (grid[nextX][nextY] == 0) {
                    q.push({nextX, nextY});
                    grid[nextX][nextY] = 2;
                }
            }
        }
        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int res = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) res += bfs(i, j, grid);
            }
        }
        return res;
    }
};