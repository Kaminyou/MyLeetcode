class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        list<tuple<int, int, int>> dq;
        distances[0][0] = grid[0][0];
        dq.push_back(make_tuple(grid[0][0], 0, 0));
        while (!dq.empty()) {
            auto [dist, x, y] = dq.front();
            dq.pop_front();
            for (auto direction : directions) {
                int _x = x + direction.first;
                int _y = y + direction.second;
                if (_x >= 0 && _x < m && _y >= 0 && _y < n && distances[_x][_y] == INT_MAX) {
                    if (grid[_x][_y] == 1) {
                        int _dist = dist + grid[_x][_y];
                        distances[_x][_y] = _dist;
                        dq.push_back(make_tuple(_dist, _x, _y));
                    }
                    else {
                        distances[_x][_y] = dist;
                        dq.push_front(make_tuple(dist, _x, _y));
                    }
                    if (_x == m - 1 && _y == n - 1) return distances[_x][_y];
                }
            }
        }
        return distances[m - 1][n - 1];
    }
};