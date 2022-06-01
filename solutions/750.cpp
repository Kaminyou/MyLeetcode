class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> onePos;
            for (int k = 0; k < n; ++k) {
                if (grid[i][k] == 1) onePos.push_back(k);
            }
            for (int j = i + 1; j < m; ++j) {
                int count = 0;
                for (auto k : onePos) {
                    if (grid[j][k] == 1) count++;
                }
                res += count * (count - 1) / 2;
            }
        }
        return res;
    }
};