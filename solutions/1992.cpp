class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> res;
    void _dfs(vector<vector<int>>& land, int i, int j, vector<int>& coords, int& num) {
        int m = land.size();
        int n = land[0].size();
        if ((i >= m) || (i < 0) || (j >= n) || (j < 0)) return;
        if (land[i][j] == -1 || land[i][j] == 0) return;
        coords[0] = min(coords[0], i);
        coords[1] = min(coords[1], j);
        coords[2] = max(coords[2], i);
        coords[3] = max(coords[3], j);
        num += 1;
        land[i][j] = -1;
        for (auto& direction : directions) {
            int x = i + direction.first;
            int y = j + direction.second;
            _dfs(land, x, y, coords, num);
        }
    }
    void dfs(vector<vector<int>>& land, int i, int j) {
        vector<int> coords = {INT_MAX, INT_MAX, -1, -1};
        int num = 0;
        _dfs(land, i, j, coords, num);
        if ((coords[2] - coords[0] + 1) * (coords[3] - coords[1] + 1) == num) {
            res.push_back(coords);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (land[i][j] == -1 || land[i][j] == 0) continue;
                dfs(land, i, j);
            }
        }
        return res;
    }
};
