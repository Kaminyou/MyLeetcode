class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = INT_MAX;
        int right = INT_MIN;
        int top = INT_MAX;
        int bottom = INT_MIN;
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                left = min(j, left);
                right = max(j, right);
                top = min(i, top);
                bottom = max(i, bottom);
                count++;
            }
        }
        if (!count) return 0;
        return (right - left + 1) * (bottom - top + 1);
    }
};
