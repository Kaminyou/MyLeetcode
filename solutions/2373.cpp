class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n - 2;
        vector<vector<int>> res(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int current = 0;
                for (int a = -1; a <= 1; ++a) {
                    for (int b = -1; b <= 1; ++b) {
                        current = max(current, grid[i + a + 1][j + b + 1]);
                    }
                }
                res[i][j] = current;
            }
        }
        return res;
    }
};