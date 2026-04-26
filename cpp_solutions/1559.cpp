class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool hasCycle(int i, int j, char c, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool res = false;
        queue<pair<int, int>> q;
        q.push({(i << 9) + j, -1});
        while (!q.empty()) {
            int k = q.size();
            for (int t = 0; t < k; ++t) {
                auto [now, prev] = q.front();
                q.pop();
                int nowX = now >> 9;
                int nowY = now & ((1 << 9) - 1);
                int prevX = -1;
                int prevY = -1;
                if (prev != -1) {
                    prevX = prev >> 9;
                    prevY = prev & ((1 << 9) - 1);
                }
                for (auto& direction : directions) {
                    int nextX = nowX + direction.first;
                    int nextY = nowY + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (nextX == prevX && nextY == prevY) continue;
                    if (grid[nextX][nextY] != c) continue;
                    if (visited[nextX][nextY]) res = true;
                    if (!visited[nextX][nextY]) {
                        visited[nextX][nextY] = true;
                        q.push({(nextX << 9) + nextY, (nowX << 9) + nowY});
                    }
                }
            }
        }
        return res;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                char c = grid[i][j];
                if (hasCycle(i, j, c, visited, grid)) return true;
            }
        }
        return false;
    }
};
