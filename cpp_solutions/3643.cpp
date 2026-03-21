class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int xx = x + k - 1;
        while (x < xx) {
            for (int i = 0; i < k; ++i) {
                swap(grid[x][y + i], grid[xx][y + i]);
            }
            x++;
            xx--;
        }
        return grid;
    }
};
