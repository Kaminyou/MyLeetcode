class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void collectGrid(int i, int j, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        for (auto& direction : directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            collectGrid(x, y, q, grid);
        }
    } 
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool flag = false;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m && !flag; ++i) {
            for (int j = 0; j < n && !flag; ++j) {
                if (grid[i][j] == 1) {
                    collectGrid(i, j, q, grid);
                    flag = true;
                }
            }
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& direction : directions) {
                    int nextX = x + direction.first;
                    int nextY = y + direction.second;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (grid[nextX][nextY] == 2) continue;
                    if (grid[nextX][nextY] == 1) return steps;
                    q.push({nextX, nextY});
                    grid[nextX][nextY] = 2;
                }
            }
            steps++;
        }
        return steps;
    }
};