class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
            }
        }
        long long temp = 0;
        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                temp += grid[i][j];
            }
            if (temp == sum - temp) return true;
        }
        temp = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = 0; i < m; ++i) {
                temp += grid[i][j];
            }
            if (temp == sum - temp) return true;
        }
        return false;
    }
};
