class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool parse(int x, int y, vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        long long sum = 0;
        queue<pair<int, int>> q;
        sum += grid[x][y];
        q.push({x, y});
        grid[x][y] = 0;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int xx = currX + direction.first;
                int yy = currY + direction.second;
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (grid[xx][yy] == 0) continue;
                sum += grid[xx][yy];
                q.push({xx, yy});
                grid[xx][yy] = 0;
            }
        }
        return sum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) res += parse(i, j, grid, k);
            }
        }
        return res;
    }
};

