class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }
        
        int ans = 0;
        vector<int> col(m, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            sort(col.begin(), col.end(), greater<int>());
            ans += col[0];
        }
        return ans;
    }
};