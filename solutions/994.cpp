class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int>> q;
        int freshCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                else if (grid[i][j] == 1) freshCount++;
            }
        }
        int res = 0;
        while (!q.empty()) {
            int length = q.size();
            int plus = 0;
            while (length--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto direction : directions) {
                    int _x = x + direction.first;
                    int _y = y + direction.second;
                    if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                    if (grid[_x][_y] == 1) {
                        q.push(make_pair(_x, _y));
                        grid[_x][_y] = 2;
                        freshCount--;
                        plus++;
                    }
                }
            }
            if (plus) res++;
        }
        if (freshCount > 0) return -1;
        return res;
    }
};