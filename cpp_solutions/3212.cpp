class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> xs(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ys(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                xs[i + 1][j + 1] = xs[i + 1][j] + xs[i][j + 1] - xs[i][j] + (grid[i][j] == 'X');
                ys[i + 1][j + 1] = ys[i + 1][j] + ys[i][j + 1] - ys[i][j] + (grid[i][j] == 'Y');
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = xs[i + 1][j + 1] - xs[0][j + 1] - xs[i + 1][0] + xs[0][0];
                int y = ys[i + 1][j + 1] - ys[0][j + 1] - ys[i + 1][0] + ys[0][0];
                if (x >= 1 && x == y) res++;
            }
        }
        return res;
    }
};
