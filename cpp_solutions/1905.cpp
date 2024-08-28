class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<int>>& grid2, vector<vector<int>>& grid1, int i, int j) {
        int m = grid1.size();
        int n = grid1[0].size();
        bool valid = true;
        grid2[i][j] = 0;
        if (!grid1[i][j]) valid = false;
        for (auto& direction : directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (!grid2[x][y]) continue;
            bool result = dfs(grid2, grid1, x, y);
            if (!result) valid = false;
        }
        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 0) continue;
                if (dfs(grid2, grid1, i, j)) cnt++;
            }
        }
        return cnt;
    }
};
