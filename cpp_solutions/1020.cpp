class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 2;
        bool isInMiddle = true;
        int count = 0;
        while (!q.empty()) {
            auto [currentX, currentY] = q.front();
            q.pop();
            count++;
            for (auto& direction : directions) {
                int nextX = currentX + direction.first;
                int nextY = currentY + direction.second;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
                    isInMiddle = false;
                    continue;
                }
                if (grid[nextX][nextY] != 1) continue;
                q.push({nextX, nextY});
                grid[nextX][nextY] = 2;
            }
        }
        return count * isInMiddle;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) count += bfs(i, j, grid);
            }
        }
        return count;
    }
};