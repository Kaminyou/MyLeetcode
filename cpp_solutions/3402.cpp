class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int j = 0; j < n; ++j) {
            int current = grid[0][j];
            for (int i = 1; i < m; ++i) {
                current = max(current + 1, grid[i][j]);
                res += (current - grid[i][j]);
            }
        }
        return res;
    }
};
