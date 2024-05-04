class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distances(m, vector<int>(n, 0));
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int currAcceptable = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    int distance = 0;
                    while (!q.empty()) {
                        int k = q.size();
                        distance++;
                        while (k--) {
                            auto [x, y] = q.front();
                            q.pop();
                            for (auto direction : directions) {
                                int _x = x + direction.first;
                                int _y = y + direction.second;
                                if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                                if (grid[_x][_y] != currAcceptable) continue;
                                grid[_x][_y] = currAcceptable - 1;
                                q.push(make_pair(_x, _y));
                                distances[_x][_y] += distance;
                            }
                        }
                    }
                    currAcceptable--;
                } 
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == currAcceptable) res = min(res, distances[i][j]);
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
};