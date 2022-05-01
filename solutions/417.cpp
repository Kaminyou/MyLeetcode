class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // pacific
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push(make_pair(i, 0));
            canReachPacific[i][0] = true;
        }
        for (int j = 1; j < n; j++) {
            q.push(make_pair(0, j));
            canReachPacific[0][j] = true;
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto direction : directions) {
                int _x = x + direction.first;
                int _y = y + direction.second;
                if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                if (canReachPacific[_x][_y]) continue;
                if (heights[x][y] > heights[_x][_y]) continue;
                q.push(make_pair(_x, _y));
                canReachPacific[_x][_y] = true;
            }
        }
        
        while (!q.empty()) q.pop();
        
        // atlantic
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            q.push(make_pair(i, n - 1));
            canReachAtlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n - 1; j++) {
            q.push(make_pair(m - 1, j));
            canReachAtlantic[m - 1][j] = true;
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto direction : directions) {
                int _x = x + direction.first;
                int _y = y + direction.second;
                if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
                if (canReachAtlantic[_x][_y]) continue;
                if (heights[x][y] > heights[_x][_y]) continue;
                q.push(make_pair(_x, _y));
                canReachAtlantic[_x][_y] = true;
            }
        }
        
        // final
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};