class Solution {
public:
    int minDiff(vector<vector<int>>& grid, int r, int c, int k, vector<int>& temp) {
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                temp[i * k + j] = grid[r + i][c + j];
            }
        }
        sort(temp.begin(), temp.end());
        int res = INT_MAX;
        bool flag = false;
        for (int i = 0; i < k * k - 1; ++i) {
            if (temp[i] != temp[i + 1]) {
                flag = true;
                res = min(res, temp[i + 1] - temp[i]);
            }
        }
        if (flag) return res;
        return 0;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, 0));
        vector<int> temp(k * k, 0);
        for (int i = 0; i < m - k + 1; ++i) {
            for (int j = 0; j < n - k + 1; ++j) {
                res[i][j] = minDiff(grid, i, j, k, temp);
            }
        }
        return res;
    }
};
