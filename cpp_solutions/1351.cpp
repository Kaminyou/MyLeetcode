class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        int x = m - 1;
        int y = 0;
        while (x >= 0) {
            while (y < n && grid[x][y] >= 0) y++;
            res += n - y;
            x--;
        }
        return res;
    }
};