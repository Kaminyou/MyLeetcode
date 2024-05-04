class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        vector<pair<int, int>> directions = {{0, 1}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res += 4;
                    for (auto& direction : directions) {
                        int _x = i + direction.first;
                        int _y = j + direction.second;
                        if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                        else if (grid[_x][_y] == 1) res -= 2;
                    }
                }
             }
        }
        return res;
    }
};