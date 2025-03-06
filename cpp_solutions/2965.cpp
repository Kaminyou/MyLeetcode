class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> visited(n * n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[grid[i][j] - 1] += 1;
            }
        }
        vector<int> res(2, 0);
        for (int i = 0; i < n * n; ++i) {
            if (visited[i] == 0) res[1] = i + 1;
            if (visited[i] == 2) res[0] = i + 1;
        }
        return res;
    }
};
