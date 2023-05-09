class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m * n, 0);
        int x = 0;
        int y = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0;
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[x][y];
            matrix[x][y] = -200;
            int nextX = x + directions[idx].first;
            int nextY = y + directions[idx].second;
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || matrix[nextX][nextY] == -200) idx = (idx + 1) % 4;
            x += directions[idx].first;
            y += directions[idx].second;
        }
        return res;
    }
};