class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int first = 0;
        for (int i = 1; i < m; ++i) {
            // check first
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != grid[first][j]) {
                    flag = false;
                    break;
                }
            }
            // check flip
            if (!flag) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] ^ grid[first][j] != 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};