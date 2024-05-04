class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        if (q.size() == m * n || q.size() == 0) return -1;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                if (distance[nextX][nextY] != INT_MAX) continue;
                q.push({nextX, nextY});
                distance[nextX][nextY] = distance[x][y] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, distance[i][j]);
            }
        }
        return res;
    }
};