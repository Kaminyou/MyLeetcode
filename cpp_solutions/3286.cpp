class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int m = grid.size();
        int n = grid[0].size();
        pq.push({-grid[0][0], {0, 0}});
        grid[0][0] = -1;
        while (!pq.empty()) {
            auto [v, p] = pq.top();
            auto [x, y] = p;
            pq.pop();
            if (x == m - 1 && y == n - 1) return health >= 1 - v;
            for (auto& direction : directions) {
                int xx = x + direction.first;
                int yy = y + direction.second;
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if (grid[xx][yy] == -1) continue;
                int vv = v - grid[xx][yy];
                grid[xx][yy] = -1;
                pq.push({vv, {xx, yy}});
            }
        }
        return false;
    }
};
