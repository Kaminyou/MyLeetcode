class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        
        q.push(make_pair(1, make_pair(0, 0)));
        grid[0][0] = 1;
        while (!q.empty()) {
            auto [level, position] = q.front();
            auto [x, y] = position;
            if (x == n - 1 && y == n - 1) return level;
            q.pop();
            for (auto direction : directions) {
                int _x = x + direction.first;
                int _y = y + direction.second;
                if (_x < 0 || _x >= n || _y < 0 || _y >= n) continue;
                if (grid[_x][_y] != 0) continue;
                q.push(make_pair(level + 1, make_pair(_x, _y)));
                grid[_x][_y] = 1;
            }
        }
        return -1;
    }
};