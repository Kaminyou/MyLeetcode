class Solution {
public:
    vector<pair<int ,int >> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int x = i + direction.first;
                int y = j + direction.second;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (grid[x][y] != 0) continue;
                grid[x][y] = grid[i][j] + 1;
                q.push({x, y});
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});
        while (get<1>(pq.top()) < n - 1 || get<2>(pq.top()) < n - 1) {
            auto [val, i, j] = pq.top();
            pq.pop();
            for (auto& direction : directions) {
                int x = i + direction.first;
                int y = j + direction.second;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;
                if (grid[x][y] < 0) continue;
                pq.push({min(val, grid[x][y]), x, y});
                grid[x][y] *= -1;
            }
        }
        return get<0>(pq.top()) - 1;
    }
};
