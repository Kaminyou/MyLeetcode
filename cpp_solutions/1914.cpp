class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int l = min(m / 2, n / 2);
        vector<int> nums(2 * m + 2 * n, 0);
        for (int t = 0; t < l; ++t) {
            int index = 0;
            // x: [t, n - t - 1]
            // y: [t, m - t - 1]
            for (int i = t; i < m - t - 1; ++i) {
                nums[index] = grid[i][t];
                index++;
            }
            for (int j = t; j < n - t - 1; ++j) {
                nums[index] = grid[m - t - 1][j];
                index++;
            }
            for (int i = m - t - 1; i > t; --i) {
                nums[index] = grid[i][n -t - 1];
                index++;
            }
            for (int j = n - t - 1; j > t; --j) {
                nums[index] = grid[t][j];
                index++;
            }
            int cnt = 2 * (n - t - 1 - t) + 2 * (m - t - 1 - t);
            int kk = k % cnt;
            index = 0;
            for (int i = t; i < m - t - 1; ++i) {
                grid[i][t] = nums[(index - kk + cnt) % cnt];
                index++;
            }
            for (int j = t; j < n - t - 1; ++j) {
                grid[m - t - 1][j] = nums[(index - kk + cnt) % cnt];
                index++;
            }
            for (int i = m - t - 1; i > t; --i) {
                grid[i][n -t - 1] = nums[(index - kk + cnt) % cnt];
                index++;
            }
            for (int j = n - t - 1; j > t; --j) {
                grid[t][j] = nums[(index - kk + cnt) % cnt];
                index++;
            }
        }
        return grid;
    }
};
