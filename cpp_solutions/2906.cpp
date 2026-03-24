class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> up(m + 2, 1);
        vector<int> down(m + 2, 1);
        for (int i = 0; i < m; ++i) {
            up[i + 1] = up[i]; 
            for (int j = 0; j < n; ++j) {
                up[i + 1] *= (grid[i][j] % 12345);
                up[i + 1] %= 12345;
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            down[i + 1] = down[i + 2];
            for (int j = 0; j < n; ++j) {
                down[i + 1] *= (grid[i][j] % 12345);
                down[i + 1] %= 12345;
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<int> right(n + 2, 1);
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                right[j + 1] = right[j + 2] * (grid[i][j] % 12345);
                right[j + 1] %= 12345;
            }
            int left = 1;
            for (int j = 0; j < n; ++j) {
                long long temp = (long long)left * right[j + 2] * up[i] * down[i + 2];
                res[i][j] = temp % 12345;
                left *= (grid[i][j] % 12345);
                left %= 12345;
            }
        }
        return res;
    }
};
