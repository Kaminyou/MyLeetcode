class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return 0;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<tuple<int, int, int, int>> q; // x, y, path, delete
        q.push(make_tuple(0, 0, 0, 0));
        visited[0][0][0] = true;
        while (!q.empty()) {
            auto [x, y, path, eliminate] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = x + direction.first;
                int nextY = y + direction.second;
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                if (nextX == m - 1 && nextY == n - 1) return path + 1;
                if (grid[nextX][nextY] != 1 && !visited[nextX][nextY][eliminate]) {
                    visited[nextX][nextY][eliminate] = true;
                    q.push(make_tuple(nextX, nextY, path + 1, eliminate));
                }
                if (grid[nextX][nextY] == 1 && eliminate + 1 <= k && !visited[nextX][nextY][eliminate + 1]) {
                    visited[nextX][nextY][eliminate + 1] = true;
                    q.push(make_tuple(nextX, nextY, path + 1, eliminate + 1));
                }
            }
        }
        return -1;
    }
};