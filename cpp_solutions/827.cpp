class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, int x, int y, int index, unordered_map<int, int>& islandSize) {
        int n = grid.size();
        grid[x][y] = index;
        islandSize[index]++;
        for (auto& direction : directions) {
            int xx = x + direction.first;
            int yy = y + direction.second;
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
            if (grid[xx][yy] != 1) continue;
            dfs(grid, xx, yy, index, islandSize);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int index = -1;
        unordered_map<int, int> islandSize;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) dfs(grid, i, j, index, islandSize);
                index--;
            }
        }
        int res = 0;
        for (auto& [k, v] : islandSize) {
            res = max(res, v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> temp;
                    int cnt = 1;
                    for (auto& direction : directions) {
                        int xx = i + direction.first;
                        int yy = j + direction.second;
                        if (xx < 0 || xx >= n || yy < 0 || yy >=n ) continue;
                        if (grid[xx][yy] == 0) continue;
                        int key = grid[xx][yy];
                        temp[key] = islandSize[key];
                    }
                    for (auto& [k, v] : temp) {
                        cnt += v;
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};
