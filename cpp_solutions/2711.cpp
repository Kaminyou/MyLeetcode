class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = m + n - 1;
        int shift = m - 1;
        vector<unordered_set<int>> stTopLeft(count);
        vector<unordered_set<int>> stBottomRight(count);
        vector<vector<int>> topLeft(m, vector<int>(n, 0));
        vector<vector<int>> buttomRight(m, vector<int>(n, 0));
        vector<vector<int>> answer(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int index = j - i;
                topLeft[i][j] = stTopLeft[index + shift].size();
                stTopLeft[index + shift].insert(grid[i][j]);
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int index = j - i;
                buttomRight[i][j] = stBottomRight[index + shift].size();
                stBottomRight[index + shift].insert(grid[i][j]);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                answer[i][j] = abs(topLeft[i][j] - buttomRight[i][j]);
            }
        }
        return answer;
    }
};