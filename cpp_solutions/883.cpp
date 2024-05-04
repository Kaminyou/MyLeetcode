class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        // xy
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) res++;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int maxValue = 0;
            for (int j = 0; j < n; ++j) {
                maxValue = max(maxValue, grid[i][j]);
            }
            res += maxValue;
        }
        for (int j = 0; j < n; ++j) {
            int maxValue = 0;
            for (int i = 0; i < n; ++i) {
                maxValue = max(maxValue, grid[i][j]);
            }
            res += maxValue;
        }
        return res;
    }
};
