class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int> rowCnt;
        unordered_map<int, int> colCnt;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCnt[i] >= 2 || colCnt[j] >= 2) res++;
                }
            }
        }
        return res;
    }
};
